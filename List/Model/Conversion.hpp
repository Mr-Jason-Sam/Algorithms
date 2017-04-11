//
//  Conversion.hpp
//  List
//
//  Created by Jason_Sam on 22/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#ifndef Conversion_hpp
#define Conversion_hpp

#include <stdio.h>

class Conversion{
public:
    Conversion();
    ~Conversion();
    virtual int operate() = 0;
};

class _16to10_:Conversion{
public:
    _16to10_(int );
    ~_16to10_();
};







#endif /* Conversion_hpp */
