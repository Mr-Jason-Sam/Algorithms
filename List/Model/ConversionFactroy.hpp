//
//  ConversionFactroy.hpp
//  List
//
//  Created by Jason_Sam on 22/03/2017.
//  Copyright © 2017 Jason_Sam. All rights reserved.
//

#ifndef ConversionFactroy_hpp
#define ConversionFactroy_hpp

#include <stdio.h>
#include "Conversion.hpp"

class Conversion_factroy{
public:
    Conversion_factroy();
    virtual ~Conversion_factroy();
    virtual Conversion* create_conversion() = 0;
};

#endif /* ConversionFactroy_hpp */
