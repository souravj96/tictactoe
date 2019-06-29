#include <stdio.h>
#include <stdbool.h> 
char arr[3][3] = {'*','*','*','*','*','*','*','*','*'};
int pos1, pos2, user=0, input=0;


void print_puzzel() {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
          printf("%c\t", arr[i][j]);  
        }
        printf("\n");
    }
}

void take_usr_input() {
    printf("choose the posotion (user %d): ", user);
    scanf("%d%d", &pos1, &pos2);
    if(arr[pos1][pos2] == '*') {
        printf("\nyou choose %d %d", pos1, pos2);
        if(user == 1) {
            arr[pos1][pos2] = '1';
            user = 0;
        }
        else {
            arr[pos1][pos2] = '0';
            user = 1;
        }
    print_puzzel();
    }
    else {
        printf("\nsorry! this position already booked!");
    }
}
bool check_v_match() {
    for (int i=0; i<3; i++) {
        if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
            printf("\nv success");
            return true;
        }
        else return false;
    }
}
bool check_h_match() {
    for (int i=0; i<3; i++) {
        if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
            printf("\nh success");
            return true;
        }
        else return false;
    }
}
bool check_d_match() {
    if((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])) {
        printf("\nd success");
        return true;
    }
    else return false;
}

int main()
{
    while(input<9) {
        take_usr_input();
        if(input>3) {
            printf("\nchecking......");
            bool h = check_h_match();
            bool v = check_v_match();
            bool d = check_d_match();
            if(h || v || d) {
                printf("\nCongratulation! user %d wins.\n", user);
                break;
            }
            else {
                if(input == 8) {
                    printf("\nGame over!\n");
                }
            }
        }
        input++;
    }
    return 0;
}
