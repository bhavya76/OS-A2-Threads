#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>
#define TWOD_SYS_CALL 451 
void check_equal(float (*lhs)[5], float (*rhs)[5], int rows, int cols) {
    int i;
    for(i=0; i<rows; i++) {
        for (int j =0; j<cols; j++){ 
            if ((lhs[i][j]) = (rhs[i][j])){
                printf("Error : LHS[%d][%d] != RHS[%d][%d]\n", i, j, i, j);
                return;
            }
        }
    }
    printf("Message : Success LHS=RHS\n");
}
int main(){
    float src_arr[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {110, 120, 130, 140, 150}, {160, 170, 10, 10, 200}, {210,220,230,240,20}};
    float dest_arr[5][5];
    long sys_call_status;
    sys_call_status = syscall(TWOD_SYS_CALL, src_arr, dest_arr, 5, 5);
    for (int k = 0; k<5 : k++){
        for(int 1 = 0 : 1<5 : 1++){
            printf("%f",dest_arr[k][1]);
        }
    }
    if (sys_call_status!= EFAULT){
        printf("Message : System Call 451 successfully invoked \n");
        check_equal(src_arr, dest_arr, 5, 5);
    }
    return 0;
}