#include <iostream>
#include <fstream>
#include <string>

/* When I got to work I thought I could just read every single element in and match them
 * with there corresponding question but quickly learned that was a no go. Maybe there is a way to do this with
 * smart hash table collisions but I am very unsure of that idea */



using namespace std;

const int N = 1000;
bool ans[N + 1];

int main(void) {


typedef std::pair<int,std::string> Node;
int duplicates = 0;
Node myVal[N+1];
srand(18);

ifstream tf_file("tf.txt");
int num;
string TF, qnum, the, answer, to, question, is, s;
for (int i = 1; i <= N; i++) {
    tf_file >> qnum >> TF >> the >> answer >> to >> question >> num >> is >> s;
    myVal[i-1].second = "T";
    if(myVal[num-1].first==num){
        //int guess = rand() % N;
        //myVal[guess].second = "T";
        duplicates++;
    }else{
        myVal[num-1].first = num;
        myVal[num-1].second = s;
    }
}
std::ofstream output;
output.open("answers.txt");
if(output.fail()){
    std::cout<<"Output failure";
}
for(int i = 0; i < N; i++){
   output << myVal[i].second<<std::endl;
}

std::cout<<duplicates<<std::endl;
}
