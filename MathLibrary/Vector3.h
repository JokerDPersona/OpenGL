//
// Created by 李圳熊 on 2022/8/29.
//

#ifndef OPENGL_VECTOR3_H
#define OPENGL_VECTOR3_H

// 向量类 不要设计虚函数 和 使用信息屏蔽(访问修饰符)
class Vector3 {
public:
    float x, y, z;

    //构造函数
    Vector3() {}

    //复制构造函数
    Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z) {}

    //带参构造函数
    Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

    //重载运算符 实现左值
    Vector3 &operator=(const Vector3 &a) {
        x = a.x;
        y = a.y;
        z = a.z;
        return *this;
    }

    bool operator==(const Vector3 &a) const {
        return x == a.x && y == a.y && z == a.z;
    }

    bool operator!=(const Vector3 &a) const {
        return x != a.x && y != a.y && z != a.z;
    }

    //向量置零
    void zero() { x = y = z = 0.0f }

    //重载一元运算
    Vector3 operator-() const { return Vector3(-x, -y, -z); }

    //重载二元运算
    Vector3 operator+(const Vector3 &a) const {
        return Vector3(x + a.x, y + a.y, z + a.z);
    }

    Vector3 operator-(const Vector3 &a) const {
        return Vector3(x - a.x, y - a.y, z - a.z);
    }

    //重载与标量的乘除
    Vector3 operator*(const Vector3 &a) const {
        return Vector3(x * a, y * a, z * a);
    }

    Vector3 operator/(const Vector3 &a) const {
        float oneOverA = 1.0f / a;
        return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
    }

    //重载自返运算符
    Vector3 &operator+=(const Vector3 &a) {
        x += a;
        y += a;
        z += a;
        return *this;
    }

    Vector3 &operator-=(const Vector3 &a) {
        x -= a;
        y -= a;
        z -= a;
        return *this;
    }

    Vector3 &operator*=(const Vector3 &a) {
        x *= a;
        y *= a;
        z *= a;
        return *this;
    }

    Vector3 &operator/=(const Vector3 &a) {
        float oneOverA = 1.0f / a;
        x *= oneOverA;
        y *= oneOverA;
        z *= oneOverA;
        return *this;
    }

    //标量化
    Vector3 normalize() {
        float magSq = x * x + y * z + z * z;
        if (magSq > 0.0f) {
            float oneOverMag = 1.0f / sqrt(magSq);
            x *= oneOverMag;
            y *= oneOverMag;
            z *= oneOverMag;
        }
    }

    // 点乘，重载标准乘法
    Vector3 operator*(const Vector3 &a) const {
        return x * a.x + y * a.y + z * a.z;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////
    //// 非成员函数
    ////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //向量求摸 平方和
    inline float VectorMag(const Vector3 &a) {
        return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    }

    //向量叉乘
    inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b) {
        return Vector3(
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
        );
    }

    //标量左乘
    inline Vector3 operator*(float k, const Vector3 &v) {
        return Vector3(k * v.x, k * v.y, k * v.z);
    }

    //两点距离
    inline float distance(const Vector3 &a, const Vector3 &b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        float dz = a.z - b.z;
        //平方和
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////
    //// 全局变量
    ////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // 全局零向量
    extern const Vector3 kZeroVector;
};

#endif //OPENGL_VECTOR3_H
