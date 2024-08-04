/**
 * Author: alexxela12345,daubi,talant
 * Date: 2024-08-03
 * Description: Polygon functions
 */

vector<point> hull(vector<point> p) {
    point mn = {inf,inf};
    for(auto i : p) {
        if(i.x > mn.x || (i.x == mn.x && i.y < mn.y)) mn = i;
    }
    for(auto &i : p) i = i - mn;
    sort(all(p), [&](point &a, point &b) -> bool {
        int sgn = sign(a % b);
        if (!sgn) {
            return len2(a) < len2(b);
        }
        return sgn == 1;
    });
    for(auto &i : p) i = i + mn;
    int top = 0;
    for (int i = 0; i < n; ++i) {
        while (top >= 2) {
            vec v1 = p[top - 1] - p[top - 2];
            vec v2 = p[i] - p[top - 1];
            if (sign(v1 % v2) == 1)
                break;
            --top;
        }
        p[top++] = p[i];
    }
    p.resize(top);
    return p;
}