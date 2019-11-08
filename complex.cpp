#include "complex.hpp"
#include <cmath>



complex::complex() {
    r = 0;
    fi = 0;    
}

complex complex::add(const complex& o) const {
    complex result;
    double cos_1 = cos ( fi * M_PI );
    double cos_2 = cos ( o.fi * M_PI );
    double sin_1 = sin ( fi * M_PI );
    double sin_2 = sin ( o.fi * M_PI );
    double a_1 = r * cos_1;
    double a_2 = o.r * cos_2;
    double b_1 = r * sin_1;
    double b_2 = o.r * sin_2;
    double a_r = a_1 + a_2;
    double b_r = b_1 + b_2;
    result.r = sqrt( a_r * a_r + b_r * b_r );

    //ПЕРВАЯ ЧЕТВЕРТЬ    
    if (a_r / result.r > 0 and b_r /result.r >= 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ВТОРАЯ
    if (a_r / result.r <= 0 and b_r /result.r > 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ТРЕТЬЯ
    if (a_r / result.r >= 0 and b_r /result.r < 0) {
        result.fi = ( asin ( b_r / result.r) ) / M_PI;
    }
    //ЧЕТВЕРТАЯ
    if (a_r / result.r < 0 and b_r /result.r <= 0) {
        result.fi = - ( acos ( a_r / result.r) ) / M_PI;
    }

    return result;
}


complex complex::sub(const complex& o) const {
    complex result;
    double cos_1 = cos ( fi * M_PI );
    double cos_2 = cos ( (o.fi - 1) * M_PI);
    double sin_1 = sin ( fi * M_PI );
    double sin_2 = sin ( (o.fi - 1) * M_PI);
    double a_1 = r * cos_1;
    double a_2 = o.r * cos_2;
    double b_1 = r * sin_1;
    double b_2 = o.r * sin_2;
    double a_r = a_1 + a_2;
    double b_r = b_1 + b_2;
    result.r = sqrt( a_r * a_r + b_r * b_r );
    
    //ПЕРВАЯ ЧЕТВЕРТЬ    
    if (a_r / result.r > 0 and b_r /result.r >= 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ВТОРАЯ
    if (a_r / result.r <= 0 and b_r /result.r > 0) {
        result.fi = ( acos ( a_r / result.r) ) / M_PI;
    }
    //ТРЕТЬЯ
    if (a_r / result.r >= 0 and b_r /result.r < 0) {
        result.fi = ( asin ( b_r / result.r) ) / M_PI;
    }
    //ЧЕТВЕРТАЯ
    if (a_r / result.r < 0 and b_r /result.r <= 0) {
        result.fi = - ( acos ( a_r / result.r) ) / M_PI;
    }

    return result;
}


complex complex::mul(const complex& o) const {
    complex result;
    double cos_1 = cos ( fi * M_PI );
    double cos_2 = cos ( o.fi * M_PI );
    double sin_1 = sin ( fi * M_PI );
    double sin_2 = sin ( o.fi * M_PI );
    double a_1 = r * cos_1;
    double a_2 = o.r * cos_2;
    double b_1 = r * sin_1;
    double b_2 = o.r * sin_2;
    double a_r = a_1 + a_2;
    double b_r = b_1 + b_2;
    result.r = r * o.r;
    result.fi = fi + o.fi;

    return result;
}

complex complex::div(const complex& o) const {
    complex result;
    double cos_1 = cos ( fi * M_PI );
    double cos_2 = cos ( o.fi * M_PI );
    double sin_1 = sin ( fi * M_PI );
    double sin_2 = sin ( o.fi * M_PI );
    double a_1 = r * cos_1;
    double a_2 = o.r * cos_2;
    double b_1 = r * sin_1;
    double b_2 = o.r * sin_2;
    double a_r = a_1 + a_2;
    double b_r = b_1 + b_2;
    result.r = r / o.r;
    result.fi = fi - o.fi;
    return result;
}


int complex::equ(const complex& o) const {
    if ((r == o.r) && (fi == o.fi)) {
        return 1;
    }
    return 0;
}

complex complex::conj(const complex& o) const {
    complex result;
    result.r = r;
    result.fi = -fi;
    return result;
}

void complex::read(std::istream& is) {
	double a, b;
	is >> a;
	is >> b;
    if ( b >= 2 ) {
        b = fmod( b, 2 );
    } else if ( b < 0 ) {
        b = fmod( b, 2 ) + 2;
    }
	this->r = a;
	this->fi = b;
}

void complex::write(std::ostream& os) const{
	os << this->r << " " << this->fi << "p\n";
}
