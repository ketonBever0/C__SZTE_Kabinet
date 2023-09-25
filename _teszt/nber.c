#include <stdio.h>

void legkozelebbi(int nber1, int nber2, int nber3) {

    // 1 - 2
    int dist1_2;
    if (nber1 >= nber2) dist1_2 = nber1 - nber2;
    else dist1_2 = nber2 - nber1;

    // 1 - 3
    int dist1_3;
    if (nber1 >= nber3) dist1_3 = nber1 - nber3;
    else dist1_3 = nber3 - nber1;

    // 2 - 3
    int dist2_3;
    if (nber2 >= nber3) dist2_3 = nber2 - nber3;
    else dist2_3 = nber3 - nber2;

    printf("1 - 2: %d\n", dist1_2);
    printf("1 - 3: %d\n", dist1_3);
    printf("2 - 3: %d\n", dist2_3);


    // if (dist1_2 == dist1_3 || dist1_2 == dist2_3 || dist1_3 == dist2_3){
    //     printf("bizonyosok kozott ugyanakkora");
    //     return;
    // }

    if (dist1_2 < dist1_3 && dist1_2 < dist2_3) printf("Az elso es a masodik van a legkozelebb egymashoz");
    if (dist1_3 < dist1_2 && dist1_3 < dist2_3) printf("Az elso es a harmadik van a legkozelebb egymashoz");
    if (dist2_3 < dist1_2 && dist2_3 < dist1_3) printf("A masodik es a harmadik van a legkozelebb egymashoz");
    

}


int main() {
 
    legkozelebbi(30, 10, 20);

    return 0;
}