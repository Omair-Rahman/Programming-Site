#include<bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
#define x first
#define y second
#define eps 1e-9
using namespace std ;


#define MAXD 2
#define FOR(i,b,c) for(int i = b ; i < c ; i++ )
#define eps 1e-9
#define pi acos(-1.0)

struct myVec {

  int d; //Dimension
  double val[MAXD];//Contains value of each component
  myVec() {
    d=2;
  }
  myVec( double a , double b ,double c ) {
    val[0] = a ;
    val[1] = b ;
    val[2] = c ;
    d = 3 ;
  }
  myVec( double a , double b ) {
    val[0] = a ;
    val[1] = b ;
    d = 2 ;
  }
  myVec add ( myVec b ) {
    myVec res;
    FOR(i,0,d) res.val[i] = val[i] + b.val[i];
    return res;
  }
  myVec sub ( myVec b ) {
    myVec res;
    FOR(i,0,d) res.val[i] = val[i] - b.val[i];
    return res;
  }
  myVec mul ( double t ) {
    myVec res;
    FOR(i,0,d)res.val[i] = val[i] * t;
    return res;
  }
  myVec div ( double t ) {
    myVec res;
    FOR(i,0,d) res.val[i] = val[i] / t;
    return res;
  }
  bool operator == ( myVec b ) {
    FOR(i,0,d) if ( fabs ( val[i] - b.val[i] ) > eps ) return false;
    return true;
  }
  bool operator < ( const myVec & b )const  {
    for(int i=0; i<d; i++) {
      if ( fabs ( val[i] - b.val[i] ) < 1e-6 ) continue ;
      else return val[i]+eps < b.val[i] ;
    }
    return true;
  }
  myVec perp2D() {
    myVec res = (*this);
    swap ( res.val[0], res.val[1] );
    res.val[0] *= -1;
    return res;
  }
  double dot ( myVec v ) { //Finds *this (dot) v
    double res = 0;
    d = 2 ;
    for ( int i = 0; i < d; i++ ) res += val[i] * v.val[i];
    return res;
  }
  double length () { //Finds length of current myVec
    return sqrt ( this->dot( *this ) );
  }
  myVec unitVec () {
    return (*this).div ( length() ); // v / ||v||
  }
  double angleBetween ( myVec b ) { //Angle between two myVecs
    double res = dot( b ) / ( length() * b.length() );
    if ( res > 1 ) res = 1;
    if ( res < -1 ) res = -1;
    return acos (res);
  }
  double polarAngle2D() { //Angle from x-axis
    double res = atan2 ( val[1], val[0] );
    if ( res + eps < 0 ) res += 2 * pi;
    return res;
  }
  double dist( myVec a ) {
    if( a.d != d )cout << "Wrong dimension to calculate in sqdist function\n" ;
    double ret = 0 ;
    for( int i = 0 ; i < d ; i++ ) {
      ret += ( val[i] - a.val[i] )*( val[i] - a.val[i] ) ;
    }
    return sqrt(ret) ;
  }
  double cross2D ( myVec v ) { //Cross the two values. Only for 2D. Z compo 0.
    return val[0]*v.val[1] - val[1]*v.val[0];
  }    double isLeft( myVec st , myVec en ) {
    return ( (en.val[0] - st.val[0])*(val[1] - st.val[1])
             - (val[0] - st.val[0])*(en.val[1] - st.val[1]) ) ; ;
  }
};

struct myLine {
  myVec a, b; //a is displacement, b is direction.
  //Builds a myLine from two points
  myLine() {}
  myLine( myVec x, myVec y ) {
    a = x;
    b = y.sub ( x );
  }
  myLine LineFromPoints ( myVec x, myVec y ) {
    myLine m;
    m.a = x;
    m.b = y.sub ( x );
    return m;
  }
  //Finds point on myLine, given t.
  myVec atPos ( double t ) {
    return a.add ( b.mul ( t ) ); // a + tb;
  }
  double calT( myVec pt ) {
    double d1 = a.dist( pt ) ;
    double d2 = sqrt(b.val[0]*b.val[0]+b.val[1]*b.val[1]) ;
    myVec q = myVec(a.val[0]+b.val[0],a.val[1]+b.val[1]) ;

    double s1 = q.isLeft( myVec(0,0) , a );
    double s2 = pt.isLeft(myVec(0,0) , a ) ;
    double mul = 1 ;
    if( s1 >= 0 && s2 < 0 )mul = -1 ;
    if( s1 < 0 && s2 >= 0 )mul = -1 ;

    return mul*d1/d2 ;
  }
  double LineToPointDistance ( myVec p, double t ) {
    p = p.sub ( a ); //Take it to origin
    t = b.dot ( p ) / ( b.length() * b.length() ); //point of intersection
    myVec x = b.mul ( t ); //tb
    return ( p.sub(x).length() ); //xp length()
  }
  double segmentToPointDistance ( myVec p, double &t ) {
    p = p.sub ( a ); //Take it to origin
    t = b.dot ( p ) / ( b.length() * b.length() );
    if ( t + eps < 0 || t > 1 + eps ) { //Not on segment
      return min ( p.length(), p.sub(b).length() );
    }
    myVec x = b.mul ( t ); //tb
    return ( p.sub(x).length() ); //xp length()
  }
  bool overlapParallel ( myLine l ) {
    double p, q, r, s;
    if ( b.val[0] == 0 ) {
      p = a.val[1];
      q = atPos(1).val[1];
      r = l.a.val[1];
      s = l.atPos ( 1 ).val[1];
      if ( min ( r, s ) > max ( p, q ) ) return false;
      if ( max ( r, s ) < min ( p, q ) ) return false;
      return true;
    } else {
      p = a.val[0];
      q = atPos(1).val[0];
      r = l.a.val[0];
      s = l.atPos ( 1 ).val[0];
      if ( min ( r, s ) > max ( p, q ) ) return false;
      if ( max ( r, s ) < min ( p, q ) ) return false;
      return true;
    }
  }
  char LineAndLineIntersection2D ( myLine l, double &t, double &s ) {
    if ( b.cross2D ( l.b) == 0 ) {
      if ( l.a.sub(a).cross2D(l.b) == 0 ) {
        if ( overlapParallel ( l ) ) return 'o'; //overlaps
        else return 'p'; //parallel
      } else return 'd'; //disjoint and parallel
    }
    myVec w = a.sub ( l.a );
    myVec p = l.b.perp2D(), z = b.perp2D();
    t = -(w.dot(p))/p.dot(b); //for current myLine
    s = w.dot(z)/z.dot(l.b); //for myLine l
    return 'i';
  }
  double LineAndmyLineDistance2D ( myLine l ) {
    double t, s; //First check if the intersect
    char r = LineAndLineIntersection2D ( l, t, s );
    if ( r == 'i' ) return 0; //Intersects. 0 distance.
    //Parallel myLines
    return LineToPointDistance ( l.a, t );
  }
  double LineAndSegmentDistance2D ( myLine l ) {
    double t, s;
    char r = LineAndLineIntersection2D ( l, t, s );
    if ( r == 'i' && s + eps > 0 && s < 1 + eps ) {
      return 0; //Valid intersection
    }
    double res = LineToPointDistance ( l.a, t );
    res = min ( res, LineToPointDistance ( l.a.add(l.b), t ) );
    return res;
  }
  double segmentAndSegmentDistance2D ( myLine l ) {
    double t, s;
    char r = LineAndLineIntersection2D ( l, t, s );
    if ( r =='i' && t+eps > 0 && t < 1 + eps && s + eps > 0 && s < 1 + eps ) {
      return 0; //Valid intersection
    }
    double res = segmentToPointDistance ( l.a, t );
    res = min ( res, segmentToPointDistance ( l.a.add(l.b), t ) );
    res = min ( res, l.segmentToPointDistance ( a, t ) );
    res = min ( res, l.segmentToPointDistance ( a.add ( b ), t ) );
    return res;
  }
  myLine reflect ( myVec p, myVec norm ) {
    myVec ap = p.sub ( a ); //Starting to Point of Reflection
    norm = norm.unitVec();

    double d = fabs ( ap.dot ( norm ) );

    myVec m = p.add ( norm.mul ( d ) );
    myVec h = m.sub ( a ).mul ( 2 );
    m = a.add ( h );

    myLine ray = ray.LineFromPoints ( p, m );
    return ray;
  }
};

int main() {



  return 0 ;
}


