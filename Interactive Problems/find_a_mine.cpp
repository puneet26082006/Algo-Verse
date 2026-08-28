#include <bits/stdc++.h>
using namespace std ;

int ask(int x, int y){
    cout<< "? " << x <<" "<< y <<endl ;
    int d ;
    cin>> d ;

    return d ;
}


void tell(int x, int y){
    cout<< "! "<< x <<" "<< y <<endl ;

}




int main(){
    int t ;
    cin>> t ;

    while(t--){
        int n , m ;
        cin>> n >> m ;

        int d = ask(1,1) ;

        int point1_x = min(1 + d, n);
        int point1_y = d - point1_x + 2 ;

        int point2_y = min(1 + d, m);
        int point2_x = d - point2_y + 2 ;

        int ans1 = ask(point1_x, point1_y) ;
        if(ans1 == 0){
            tell(point1_x, point1_y);
            continue ;
        }

        int ans2 = ask(point2_x, point2_y);
        if(ans2 == 0){
            tell(point2_x, point2_y);
            continue ;
        }

        int new_point1_x = point1_x - ans1/2 ;
        int new_point1_y = point1_y + ans1/2 ;

        int new_point2_x = point2_x + ans2/2 ;
        int new_point2_y = point2_y - ans2/2 ;

        int ans3 = ask(new_point1_x, new_point1_y);

        if(ans3 == 0){
            tell(new_point1_x, new_point1_y);
            continue ;
        } else {
            tell(new_point2_x, new_point2_y);
            continue ;
        }


        // int ans4 = ask(new_point2_x, new_point2_y);
        // if(ans4 == 0){
        //     tell(new_point2_x, new_point2_y);
        //     continue ;
        // }

    }


}