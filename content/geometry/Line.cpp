/**
 * Author: Igor Markelov
 * Date: 2022-11-18
 * Description: struct Line
 */

struct line {
    ld a, b, c;
    void norm() {
        // for half planes
        ld d = len(vec(a, b));
        assert(sign(d) > 0);
        a /= d;
        b /= d;
        c /= d;
    }
    Line(ld _a, ld _b, ld _c) : a(_a), b(_b), c(_c) { norm(); }
    ld eval(point p) const { return a * p.x + b * p.y + c; }
    bool isIn(point p) const { return sign(eval(p)) >= 0; }
};