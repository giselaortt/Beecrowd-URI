# URL of the problem:
# https://www.beecrowd.com.br/judge/en/problems/view/1783


#include <bits/stdc++.h>
using namespace std;

struct vetor{
        double x,y;
        vetor(){}
        vetor(double x, double y){ this->x=x; this->y=y; }
        void unit(){
            double mod = sqrt(x*x + y*y);
            x /= mod;
            y /= mod;
        }
        vetor operator * (double lambda) const{
            return vetor(x*lambda,y*lambda);
        }
        vetor ort() const{
            return vetor(-y, x);
        }
        void operator = ( vetor p ) {
                this->x = p.x; this->y = p.y;
        }
        void print(){
            printf("%.2f %.2f\n", x, y );
        }
        double operator ^ ( vetor v ) const {
                return y*v.x - x*v.y;
        }
};
struct ponto{
        double x,y;
        ponto(){};
        ponto(double a, double b){ x=a;y=b;}
        ponto operator + (vetor A) const{
            return ponto(x+A.x, y+A.y);
        }
        ponto operator - (vetor A) const{
            return ponto(x - A.x,y - A.y);
        }
        ponto pm ( ponto p ) const {
            return ponto( (x+p.x)/2.0, (y+p.y)/2.0 );
        }
        void print(){
            printf("%.2f %.2f\n", x, y );
        }
        void operator = ( ponto p ) {
            this->x = p.x; this->y = p.y;
        }
};

vetor dec( ponto a, ponto b ) {
        return vetor( a.x - b.x, a.y - b.y );
}

struct line{
        ponto p;
        vetor v;
        line () {}
        line ( ponto p, vetor v ){
                this->p = p;
                this->v = v;
        }
        // conferir paralelismo primeiro
        ponto intersect ( line l1 ) const {
                double lambda, mi;
                if( v.x != 0 && v.y != 0 ) {
                        lambda =( p.x*v.y + v.x*l1.p.y - v.x*p.y - v.y*l1.p.x ) / ( l1.v.x*v.y - v.x*l1.v.y );
                        return l1.p + l1.v*lambda;
                }
                if( l1.v.x != 0 && l1.v.y != 0 ){
                        mi = ( l1.p.x*l1.v.y + l1.v.x*p.y - l1.v.x*l1.p.y - l1.v.y*p.x ) / ( v.x*l1.v.y - l1.v.x*v.y );
                        return  p + v*mi;
                }
                if( v.x == 0 ) return ponto( l1.p.x, p.y );
                return ponto( p.x, l1.p.y );
        }
};
int main() {
        ponto a, b, c, d;
        vetor v1, v2;
        int cases;
        cin >> cases;
        for( int i=0; i<cases; i++ ){
                cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
                v1 = dec( a, c );
                v2 = dec( b, d);
                v1 = v1.ort();
                v2 = v2.ort();
                line myline( a.pm( c ), v1  );
                line myline2( b.pm( d ), v2 );
                ponto ans = myline.intersect( myline2 );
                cout << "Caso #" << i+1 << ": ";
                cout << setprecision(2) << fixed << ans.x << ' ' << ans.y << endl;
        }
return 0;
}
