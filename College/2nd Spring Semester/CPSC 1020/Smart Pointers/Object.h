//
// Created by Gavin McRoy on 3/30/2020.
//

#ifndef TMP_OBJECT_H
#define TMP_OBJECT_H


class Object {
public:
    Object& operator=(const Object& object);
    friend std::ostream& operator<<(std::ostream &out,const Object &obj );
    Object(const Object &obj);
    Object();
};


#endif //TMP_OBJECT_H
