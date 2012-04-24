#ifndef Magnum_Test_ObjectTest_h
#define Magnum_Test_ObjectTest_h
/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include <QtCore/QObject>

#include "Object.h"

namespace Magnum { namespace Test {

class ObjectTest: public QObject {
    Q_OBJECT

    private slots:
        void parenting();
        void transformation();
        void absoluteTransformationWrongCamera();
        void absoluteTransformation();
        void scene();
        void dirty();

    private:
        class CleaningObject: public Object {
            public:
                CleaningObject(Object* parent = nullptr): Object(parent) {}

                inline void clean(const Matrix4& absoluteTransformation) {
                    Object::clean(absoluteTransformation);

                    cleanedAbsoluteTransformation = absoluteTransformation;
                }
                Matrix4 cleanedAbsoluteTransformation;
        };
};

}}

#endif
