#include <iostream>
#include <cmath>

# define M_PI           3.14159265358979323846  /* pi */

class DH
{


};

// 正向运动学得到落点坐标的函数
// double


int main()
{
    // 由机器人得到在标定板上四个点时
    // 轴1和轴3的转动角度
    double P1_theta1 = 55.703940 * M_PI / 180;
    double P1_theta3 = -71.914850 * M_PI / 180;
    double P2_theta1 = -1.886620 * M_PI / 180;
    double P2_theta3 = -73.019050 * M_PI / 180;
    double P3_theta1 = -19.590550 * M_PI / 180;
    double P3_theta3 = -131.320220 * M_PI / 180;
    double P4_theta1 = 98.587440 * M_PI / 180;
    double P4_theta3 = -130.008990 * M_PI / 180;

    // 已知L2的杆长是确定的，单位为毫米
    double L2 = 245.50;
    double L1; 
    
    // P1, P2, P3, P4的位置是确定的
    // P1 . . . . p2
    //  . . . . . .
    //  . . . . . .
    // P4 . . . . P3
    // x轴坐标向上, y轴坐标向左

    // 此时，易得四个点之间互相的delta距离

    // 由正向运动学公式，可由L1，L2和theta1，theta2
    // 求得落点的坐标X,Y
    // X = (cos\theta1 * cos\theta3 - sin\theta1 * sin\theta3) * L2 + cos\theta1 * L1
    // Y = (sin\theta1 * cos\theta3 + sin\theta3 * cos\theta1) * L2 + sin\theta1 * L1
    // (X1 - X2) ^ 2 + (Y1 - Y2) ^ 2 = delta P1_P2 ^ 2
    // 我们可以得到 P1 P2 ， P2 P3 ， P3 P4， P1 P3， P1 P4， P2 P4六组关系
    // 再通过这六组关系去逼近求得L1的精切值。

    // test
    std::cout << cos(P1_theta1) << std::endl;

    // 此处以P1，P3为例
    double X1 = cos(P1_theta1) * L1 + (cos(P1_theta1) * cos(P1_theta3) - sin(P1_theta1) * sin(P1_theta3)) * L2;
    double Y1 = sin(P1_theta1) * L1 + (sin(P1_theta1) * cos(P1_theta3) + sin(P1_theta3) * cos(P1_theta1)) * L2;

    double X3 = cos(P3_theta1) * L1 + (cos(P3_theta1) * cos(P3_theta3) - sin(P3_theta1) * sin(P3_theta3)) * L2;
    double Y3 = sin(P3_theta1) * L1 + (sin(P3_theta1) * cos(P3_theta3) + sin(P3_theta3) * cos(P3_theta1)) * L2;

    double Dis13^2 = 500^2 + 300^2 ;
    (X1 - X3) ^ 2 + (Y1 - Y3) ^ 2 = Dis13^2;

    X1 = 0.563469 * L1 + (0.563469 * 0.310430  - 0.826137 * -1 * 0.950596) * 245.50;
    Y1 = 0.826137 * L1 + (0.826137 * 0.310430 + (-1) * 0.950596 * 0.563469) * 245.50;

    X3 = 0.942112 * L1 + (0.942112 * (-1) * 0.660266 - (-1) * 0.335296 * (-1) * 0.751031) * 245.50;
    Y3 = (-1) * 0.335296 * L1 + ((-1) * 0.335296 * (-1) * 0.660266 + (-1) * 0.751031 * 0.942112) * 245.50;

    (-0.262668 * L1 + (235.738971 + 68.537135))^2 + (1.161433 * L1 + (-214.533173038144 - (-119.35492)))^2 = 300^2 + 500^2;

    (-0.262668 * L1 + 304.276106)^2 + (1.161433 * L1 -95.178253)^2 = 300^2 + 500^2;
    
    
    // 同理
    // double Dis23 = 300;
    // (X2 - X3) ^ 2 + (Y2 - Y3) ^ 2 = Dis23^2;
    // double Dis34 = 500;
    // (X3 - X4) ^ 2 + (Y3 - Y4) ^ 2 = Dis34^2;
    // double Dis41 = 300;
    // (X1 - X4) ^ 2 + (Y1 - Y4) ^ 2 = Dis41^2;

    // 最后就是要解L1，使上面的误差最小。
    // 输出L1
    return 0;
}