#include <stdio.h>
#include <math.h>

int main(void) {
    double x1,y1,x2,y2,x3,y3,x4,y4;
    const double EPS = 1e-9;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4) == 8) {
        double rx=0.0, ry=0.0;
        // check which point is the common endpoint (compare with epsilon)
        if (fabs(x1-x3) < EPS && fabs(y1-y3) < EPS) {
            rx = x2 + x4 - x1;
            ry = y2 + y4 - y1;
        } else if (fabs(x1-x4) < EPS && fabs(y1-y4) < EPS) {
            rx = x2 + x3 - x1;
            ry = y2 + y3 - y1;
        } else if (fabs(x2-x3) < EPS && fabs(y2-y3) < EPS) {
            rx = x1 + x4 - x2;
            ry = y1 + y4 - y2;
        } else if (fabs(x2-x4) < EPS && fabs(y2-y4) < EPS) {
            rx = x1 + x3 - x2;
            ry = y1 + y3 - y2;
        } else {
            // As a fallback (in case of tiny numeric shifts), try nearest-match by distance
            // Find pair with minimal distance and treat them as the common point
            double d13 = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
            double d14 = (x1-x4)*(x1-x4) + (y1-y4)*(y1-y4);
            double d23 = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
            double d24 = (x2-x4)*(x2-x4) + (y2-y4)*(y2-y4);
            double min = d13; int which = 13;
            if (d14 < min) { min = d14; which = 14; }
            if (d23 < min) { min = d23; which = 23; }
            if (d24 < min) { min = d24; which = 24; }
            if (which == 13) { rx = x2 + x4 - x1; ry = y2 + y4 - y1; }
            else if (which == 14) { rx = x2 + x3 - x1; ry = y2 + y3 - y1; }
            else if (which == 23) { rx = x1 + x4 - x2; ry = y1 + y4 - y2; }
            else { rx = x1 + x3 - x2; ry = y1 + y3 - y2; }
        }
        printf("%.3f %.3f\n", rx, ry);
    }
    return 0;
}
