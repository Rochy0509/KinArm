#include <Eigen/Dense>
#include <cmath>

using namespace std;

namespace KinArmMath{

    class Vector2D{
        private:
            Eigen::Vector2d vec;
        
        public:

            //Constructors
            Vector2D() : vec(0.0, 0.0){}
            Vector2D(double x, double y) : vec{x,y}{} 

            static Vector2D fromPolar(double magnitude, double angle_rad){
                return Vector2D(magnitude * cos(angle_rad),
                                magnitude * sin(angle_rad));
            }

            //Accesors
            double getX() const{ return vec[0]; }
            double getY() const{ return vec[1]; }
            void setX(double x){ vec[0] = x; }
            void setY(double y){ vec[1] = y; }
            void setAxis(double x, double y){ vec = Eigen::Vector2d(x,y); }

            //Member functions
            Vector2D add(const Vector2D& other) const{
                return Vector2D(vec[0] - other.vec[0], vec[1] - other.vec[1]);
            }
            static Eigen::Vector2d sub2D(const Eigen::Vector2d vec1, const Eigen::Vector2d vec2){
                return vec1 - vec2;
            }
            static Eigen::Vector2d scalarMultiplication(Eigen::Vector2d vec, double scaler){
                return vec * scaler;
            }
            static Eigen::Vector2d scalarDiv(Eigen::Vector2d vec, double scaler){
                return vec / scaler;
            }
            static Eigen::Vector2d unaryNegation(Eigen::Vector2d vec){
                return -vec;
            }
            static Eigen::Vector2d componentWiseMulti(Eigen::Vector2d vec1, Eigen::Vector2d vec2){
                return vec1.cwiseProduct(vec2);
            }
            static Eigen::Vector2d componentWiseDiv(Eigen::Vector2d vec1, Eigen::Vector2d vec2){
                return vec1.cwiseQuotient(vec2);
            }
    
    };

}