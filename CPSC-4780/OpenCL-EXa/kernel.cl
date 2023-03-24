__kernel void testing(){
    int4 v1 = (int4) -7;
    int4 v2 = (int4) (0, 1, 2, 3);
    v1 = abs(v1);
    v2.s23 = v1.hi;


    int8 v3 = (int8) (v1, v2.xw, v2.even);
    v3 = v3 + 2;
    printf("%d %d %d %d",v3.s0,v3.s1,v3.s2,v3.s3);
}
