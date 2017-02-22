//
//  AllTests.hpp
//  Tests
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#ifndef AllTests_hpp
#define AllTests_hpp

class VectorTests {
    
public:
    static void testVectorMultiplication();
    static void testVectorAddition();
    static void testVectorSubstraction();
    static void testVectorMagnitude();
    static void testVectorProduct();
    static void testVectorCrossProduct();
    static void testVectorLERP();
};

class MatrixTests {
    
public:
    static void testMatrixMultiplication();
    static void testMatrixTranspose();
    static void testMatrixDeterminant();
    static void testMatrixInverse();
    static void testMatrixPureScaleInverse();
    static void testMatrixPureTranslateInverse();
    static void testMatrixVectorZAxisRotation();
    static void testMatrixVectorScale();
    static void testMatrixVectorTranslate();
};

class QuaternionTests {
    
public:
    static void testQuaternionMultiplication();
    static void testQuaternionInverse();
    static void testQuaternionRotation();
    static void testQuaternionMatrix();
    static void testQuaternionLERP();
};

class PlaneTests {
public:
    static void testPlaneContainsPoint();
};

class AABBoxTests{
public:
    static void testBoxContainsPoint();
};

class FrustaTests{
public:
    static void testFrustaContainsPoint();
};

class LinkedListTests{
public:
    static void testLinkedListItemAdded();
};
#endif /* AllTests_hpp */
