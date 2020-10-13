#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

double const EPSILON = .0001;

struct Student {
    string name;
    vector<double> *productivity; // productivity[t] is productivity during minutes t..t+1
    vector<double> *productivity_sum; // productivity_sum[t] = productivity up to time t
    double cutoff; // point in time by which 1/2 fraction of productivity is spent
    double tStart, tStop; // time range to be assigned to this student by our algorithm
};

bool are_same(double a, double b) {
    return fabs(a - b) < EPSILON;
}

vector<Student> S;

void read_input() {
    ifstream input_file("productivity.txt");
    if (!input_file) {
        cout << "Issue" << endl;
    }
    string next_line;
    while (getline(input_file, next_line)) { // read one line at a time
        istringstream input_line(next_line);
        S.emplace_back(); // add new default-constructed student to end of vector S
        Student &new_student = S.back();
        input_line >> new_student.name;
        double d;
        new_student.productivity = new vector<double>;
        new_student.productivity_sum = new vector<double>;
        new_student.productivity_sum->push_back(0);
        while (input_line >> d) {
            new_student.productivity->push_back(d);
            new_student.productivity_sum->push_back(new_student.productivity_sum->back() + d);
        }
    }
    input_file.close();
}

/* return total productivity of student s up to time t */
double cumulative_productivity(Student &s, double t) {
    int iPart = min((int) t, (int) s.productivity->size() - 1);
    double dPart = t - iPart;
    return s.productivity_sum->at(iPart) + dPart * s.productivity->at(iPart);
}

/* return total productivity of a student from time t1 to time t2 */
double get_productivity(Student &s, double t1, double t2) {
    return (cumulative_productivity(s, t2) - cumulative_productivity(s, t1));
}

/* binary search between times t1 and t2 to find the point in time when
  half of the productivity of student s (between t1 and t2) has been reached
  e.g., get_productivity(t1,answer) should be half of get_productivity(t1,t2) */
double get_halfway_cutoff(Student &s, double t1, double t2) {
    /* TODO: use binary search and the get_productivity() function to return an
     * answer here that is accurate to within a tolerance of 0.0001
     * (i.e., the correct cutoff should differ from yours by at most 0.0001) */

    double getHalfWay = get_productivity(s, t1, t2) / 2.0;

    //double midPoint = t1+(t2-1) / 2.0 ;

    //  double newRangeMin = t1;
    // double newRangeMax = t2;
    //t2-=1;
    //cout<<"Matter"<<endl;
    //cout<<"Working"<<endl;

//    while (t1 <= t2) {
//        double mid = (t1 + t2) / 2.0;
//        if (get_productivity(s, t1, t2) < getHalfWay) {
//            t1 = mid + 1;
//        } else if (get_productivity(s, t1, t2) > getHalfWay) {
//            t2 = mid - 1;
//        } else {
//            return mid;
//        }
//    }
    double lowerBound = 0;
    double upperBound = t2;
    while (true) {

        double midPoint = lowerBound + (upperBound - lowerBound) / 2.0;
        if (get_productivity(s, t1, midPoint) < getHalfWay) {
            lowerBound = midPoint + 1;
        }
        if (get_productivity(s, t1, midPoint) > getHalfWay) {
            upperBound = midPoint - 1;
        }
        if (are_same(get_productivity(s, t1, midPoint), getHalfWay)) {
            return midPoint;
        }
    }
}

/* TODO: Re-order subarray of students S[s1..s2] so those it contains:
 * elements with cutoff values < val
 * followed by elements with cutoff values == val
 * followed by elements with cutoff values > val
 * for full credit, your approach should run "in place" */
int calc_partition(int s1, int s2, double val) {
    while (s1 < s2) {
        while (S.at(s1).cutoff < val) {
            s1++;
        }
        while (S.at(s2).cutoff > val) {
            s2--;
        }
        if (s1 < s2) {
            swap(S.at(s1), S.at(s2));
            s1++;
        }
    }
    return s1;
}

/* TODO: return the cutoff value of the student at a given rank within the
 * subarray S[s1..s2] (re-ordering the array is fine during the process)
 * e.g., if rank==0, we want to return the minimum cutoff of S[s1..s2] */
double quick_select(int s1, int s2, int rank) {

    if (s1 == s2) {
        return S.at(s1).cutoff;
    }
    if (rank == 0) {
        double min = 100000;
        for (auto &i : S) {
            if (i.cutoff < min) {
                min = i.cutoff;
            }
        }
        return min;
    }

    int pivotIndex = s1 + (rand() % (s2 - s1) + 1);  /*abs((s2-s1))+1)*/;
    double pivotValue = S.at(pivotIndex).cutoff;
    pivotIndex = calc_partition(s1, s2, pivotValue);

    if (rank == pivotIndex) {
        return S.at(pivotIndex).cutoff;
    } else if (rank < pivotIndex) {
        return quick_select(s1, pivotIndex - 1, rank);
        //return quick_select(pivotIndex-1,s2,rank);
    } else /*if (rank > pivotIndex) */{
        return quick_select(pivotIndex, s2, rank);
        /*len - p - 1 */
        //return quick_select(s1,pivotIndex+1,rank);
    }
}


// split time range t1...t2 across students S[s1...s2] (say, n of them), so each of the
// student time blocks represents >= 1/n of that student's total productivity
// over the range from t1...t2. Output of this function is an assignment of tstart
// and tstop for each of students S[s1...s2].
void solve(int s1, int s2, double t1, double t2) {
    // Base case -- we've narrowed things down to a single student
    if (s1 == s2) {
        S[s1].tStart = t1;
        S[s1].tStop = t2;
        return;
    }

    // Compute the halfway cutoffs for all the students in our current problem
    for (int i = s1; i <= s2; i++)
        S[i].cutoff = get_halfway_cutoff(S[i], t1, t2);

    // Find the median of the cutoff values of S[s1..s2]
    double median_cutoff = quick_select(s1, s2, (s2 - s1) / 2);

    // Partition students into two groups based on the median, using the same
    // function for partitioning you deveoped for quickselect
    calc_partition(s1, s2, median_cutoff);

    // Now recursively call solve() on two appropriate "half-sized" subproblems
    int mid = (s1 + s2) / 2;
    solve(s1, mid, t1, median_cutoff);
    solve(mid + 1, s2, median_cutoff, t2);
}

void test_quickselect() {
    int N = 7;

    // Add N random students
    for (int i = 0; i < N; i++) {
        S.emplace_back();
        S[i].cutoff = drand48() + drand48() + drand48();
    }

    // sort S[1..7] and store results
    vector<double> sorted_results;
    for (int j = 0; j < N; j++)
        sorted_results.push_back(S[j].cutoff);
    sort(sorted_results.begin(), sorted_results.end());
    cout << "\nTesting quickselect on array A (shown in sorted order):\n";
    for (int j = 0; j < N; j++) {
        cout << j << ": " << setprecision(4) << sorted_results[j] << " ";
    }
    cout << "\n";

    // see if quickselect results match these
    for (int j = 0; j < N; j++) {
        random_shuffle(S.begin(), S.end());
        cout << "\nshuffle(A[0..6]) is ";
        for (int j = 0; j < N; j++) cout << j << ": " << S[j].cutoff << " ";
        cout << "\n";
        double v = quick_select(0, N - 1, j);
        if (v == sorted_results[j])
            cout << "Rank " << j << " test succeeded!\n";
        else
            cout << "Error: quickselect for rank " << j << " gave " << v
                 << " instead of " << sorted_results[j] << "\n";
    }
}

int main() {
    // Use this to make sure your quickselect code works, then comment it out...
    //est_quickselect();

    // cout<< S.at(0).productivity_sum->at(0)<<endl;
    //cout <<S.at(0).name<<endl;


    //return 0;

    read_input();
    S.at(0);

    int N = S.size();    // # students
    double T = 24 * 7 * 60;  // upper end of time range
    solve(0, N - 1, 0, T); // compute tstart and tstop for each student

    // Print and check output
    for (int i = 0; i < N; i++) {
        double P = get_productivity(S[i], S[i].tStart, S[i].tStop);
        double minP = get_productivity(S[i], 0, T) / N;
        cout << S[i].name << " assigned to time range ["
             << S[i].tStart << ", " << S[i].tStop << "], with "
             << P << " total productivity (ideally >= " << minP << ")\n";
        if (P < minP) {
            cout << "Error: total productivity in this range too low\n";
            return 0;
        }
        for (int j = 0; j < i; j++)
            if (!(S[j].tStart >= S[i].tStop || S[i].tStart >= S[j].tStop)) {
                cout << "Error: this overlaps with the time range of " << S[j].name << "\n";
                return 0;
            }
    }
}
