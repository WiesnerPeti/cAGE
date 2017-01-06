//
//  main.cpp
//  Tests
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include <iostream>
#include "AllTests.hpp"

int main(int argc, const char * argv[]) {
    
    VectorTests::testVectorMultiplication();
    VectorTests::testVectorAddition();
    VectorTests::testVectorSubstraction();
    VectorTests::testVectorMagnitude();
    VectorTests::testVectorProduct();
    VectorTests::testVectorCrossProduct();
    VectorTests::testVectorLERP();
    
    MatrixTests::testMatrixMultiplication();
    MatrixTests::testMatrixDeterminant();
    MatrixTests::testMatrixTranspose();
    MatrixTests::testMatrixInverse();
    MatrixTests::testMatrixPureScaleInverse();
    MatrixTests::testMatrixVectorZAxisRotation();
    MatrixTests::testMatrixVectorScale();
    MatrixTests::testMatrixVectorTranslate();
    
    QuaternionTests::testQuaternionMultiplication();
    QuaternionTests::testQuaternionInverse();
    QuaternionTests::testQuaternionRotation();
    QuaternionTests::testQuaternionMatrix();
    
    return 0;
}
