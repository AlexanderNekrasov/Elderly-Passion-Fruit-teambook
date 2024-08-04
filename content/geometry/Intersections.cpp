/**
 * Author: alexxela12345,daubi,talant
 * Date: 2024-08-03
 * Description: Geometry intersections
 */

bool isCrossed(ld lx, ld rx, ld ly, ld ry) {
    if (lx > rx)
        swap(lx, rx);
    if (ly > ry)
        swap(ly, ry);
    return sign(min(rx, ry) - max(lx, ly)) >= 0;
}

// if two segments [a, b] and [c, d] has AT LEAST one common point -> true
bool isCrossed(point &a, point &b, point &c, point &d) {
    if (!isCrossed(a.x, b.x, c.x, d.x))
        return false;
    if (!isCrossed(a.y, b.y, c.y, d.y))
        return false;
    if (sign((b - a) % (c - a)) * sign((b - a) % (d - a)) == 1) return 0;
    if (sign((d - c) % (a - c)) * sign((d - c) % (b - c)) == 1) return 0;
    return 1;
}
//intersecting lines
bool intersect(line &l, line &m, point &I) {
    ld d = l.b * m.a - m.b * l.a;
    if (sign(d) == 0) {
        return false;
    }
    ld dx = m.b * l.c - m.c * l.b;
    ld dy = m.c * l.a - l.c * m.a;
    I = {dx / d, dy / d};
    return true;
}
//intersecting circles
int intersect(point o1, ld r1, point o2, ld r2, point &i1, point &i2) {
    if (r1 < r2) {
        swap(o1, o2);
        swap(r1, r2);
    }
    if (sign(r1 - r2) == 0 && o1 == o2) {
        return 3;
    }
    ld len = len(o1 - o2);
    if (sign(len - r1 - r2) == 1 || sign(r1 - len - r2) == 1) {
        return 0;
    }
    ld d = (sq(r1) - sq(r2) + sq(len)) / 2 / len;
    Vec v = norm(o2 - o1);
    Point a = o1 + v * d;
    if (sign(len - r1 - r2) == 0 || sign(len + r2 - r1) == 0) {
        i1 = a;
        return 1;
    }
    v = ort(v) * sqrt(sq(r1) - sq(d));
    i1 = a + v;
    i2 = a - v;
    return 2;
}
//intersecting line and circle
int cross(point &o, ld r, line &l, point &i1, point &i2) {
    ld len = dist(l, o);
    int sgn = sign(len - r);
    if (sgn == 1) {
        return 0;
    }
    vec v = norm(vec{l.a, l.b}) * len;
    if (sign(l.eval(o + v)) != 0) {
        v = {0, 0} - v;
    }
    point a = o + v;
    if (sgn == 0) {
        i1 = a;
        return 1;
    }
    v = norm({-l.b, l.a}) * sqrt(sq(r) - sq(len));
    i1 = a + v;
    i2 = a - v;
    return 2;
}