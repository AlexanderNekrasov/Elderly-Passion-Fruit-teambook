/**
 * Author: alexxela12345,daubi,talant
 * Date: 2024-08-03
 * Description: struct Point
 */

#define vec point
struct point {//% - cross, * - dot
    ld x, y;
};
bool operator<(const point &a, const point &b)  {
    if (sign(a.y - b.y) != 0) {
        return a.y < b.y;
    } else if (sign(a.x - b.x) != 0) {
        return a.x < b.x;
    }
    return 0;
}
point norm(point a) {
    return a / len(a);
}
int half(point a) {
    return (sign(a.y) == -1 || (sign(a.y) ==0 && a.x < 0));
}
point ort(point a) { 
    return {-a.y, a.x};
}
point turn(point a, ld ang) {
    return {a.x * cos(ang) - a.y * sin(ang), a.x * sin(ang) + a.y * cos(ang)};
}
ld getAngle(point &a, point &b) { 
    return atan2(a % b, a * b); 
}
bool cmpHalf(const point &a, const point &b) {
    if (half(a) != half(b)) {
        return half(b);
    } else {
        int sgn = sign(a % b);
        if (!sgn) {
            return len2(a) < len2(b);
        } else {
            return sgn == 1;
        }
    }
}
