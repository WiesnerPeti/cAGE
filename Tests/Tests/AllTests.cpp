//
//  AllTests.cpp
//  Tests
//
//  Created by Peti Wiesner on 2017. 01. 04..
//  Copyright © 2017. Peti Wiesner. All rights reserved.
//

#include "AllTests.hpp"

#include "Math.hpp"
#include "Assertion.h"
#include "LinkedList.hpp"
#include "AlignedAllocator.hpp"
#include "PoolAllocator.hpp"

#pragma mark - Vector Tests
void VectorTests::testVectorMultiplication()
{
    Vector v = {1,1,1};
    
    ASSERT(v.multiply(5).equals({5,5,5}));
}

void VectorTests::testVectorAddition(){
    Vector v1 = {1,1,1};
    Vector v2 = {2,2,2};
    
    ASSERT(v1.add(v2).equals({3,3,3}));
}

void VectorTests::testVectorSubstraction(){
    Vector v1 = {2,2,2};
    Vector v2 = {1,1,1};
    
    ASSERT(v1.substract(v2).equals({1,1,1}));
}

void VectorTests::testVectorMagnitude(){
    
    Vector v = {1,2,3};
    
    F32 m = v.magnitudeP2();
    
    ASSERTF32Equal(m, 14);
}

void VectorTests::testVectorProduct(){
    Vector v1 = {3,1,2};
    Vector v2 = {2,1,3};
    
    F32 p = v1.dotProduct(v2);
    
    ASSERTF32Equal(p, 13);
}

void VectorTests::testVectorCrossProduct(){
    Vector v1 = {3,1,2};
    Vector v2 = {2,1,3};
    
    Vector v3 = v1.crossProduct(v2);
    
    ASSERT(v3.equals({1,-5, 2}));
}

void VectorTests::testVectorLERP(){
    Vector v1 = {1,1,1};
    Vector v2 = {2,2,2};
    
    Vector v3 = v1.LERP(v2, 0.4);
    
    ASSERT(v3.equals({1.4, 1.4,1.4}));
}

#pragma mark - Matrix tests
void MatrixTests::testMatrixMultiplication(){
    TransMatrix m1 = {
        1,2,3,4,
        5,6,7,8,
        1,2,3,4,
        5,6,7,8
    };
    
    TransMatrix m2 = {
        1,2,1,2,
        1,2,1,2,
        1,2,1,2,
        1,2,1,2,
    };
    
    ASSERT(m1.multiply(m2).equals({
        10,20,10,20,
        26,52,26,52,
        10,20,10,20,
        26,52,26,52
    }));
}

void MatrixTests::testMatrixTranspose(){
    TransMatrix m = {
        1,2,3,4,
        5,6,6,8,
        9,10,11,12,
        13,14,15,16
    };
    
    TransMatrix transposeM = m.transpose();
    
    ASSERT(transposeM.equals(
                            {1,5,9,13,
                             2,6,10,14,
                             3,6,11,15,
                             4,8,12,16
                            }));
}

void MatrixTests::testMatrixDeterminant(){
    TransMatrix m = {
        1,2,3,4,
        5,6,6,8,
        9,10,11,12,
        13,14,15,1
    };
    
    ASSERTF32Equal(m.determinant(), 120);
}

void MatrixTests::testMatrixInverse(){
    TransMatrix m = {
        1,2,3,4,
        5,6,6,8,
        9,10,11,12,
        13,14,15,1
    };
    
    TransMatrix inverseM = m.inverse();
    
    ASSERT(inverseM.equals({
        -49/60.0,-1,19/20.0,-2/15.0,
        9/40.0,2,-57.0/40,1/5.0,
        1/2.0,-1,1/2.0,0,
        -1/30.0,0,1/10.0,-1/15.0
    }));
}

void MatrixTests::testMatrixPureScaleInverse(){
    TransMatrix m = {
        2,0,0,0,
        0,2,0,0,
        0,0,2,0,
        0,0,0,1
    };
    
    ASSERT(m.pureScaleInverse().equals({
        1/2.0,0,0,0,
        0,1/2.0,0,0,
        0,0,1/2.0,0,
        0,0,0,1
    }));
}

void MatrixTests::testMatrixPureTranslateInverse(){
    TransMatrix m = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        3,4,5,0
    };
    
    ASSERT(m.pureTranslateInverse().equals({
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        -3,-4,-5,0
    }));
}

void MatrixTests::testMatrixVectorZAxisRotation(){
    Vector v = {1,0,0,1};
    TransMatrix r = TransMatrix::rotationTransform({0,0,M_PI});
    
    Vector result = r.multiply_left(v);
    
    ASSERT(result.equals({-1,0,0}));
}

void MatrixTests::testMatrixVectorScale(){
    Vector v = {1,2,3,1};
    TransMatrix r = TransMatrix::scaleTransform({1,2,3});
    
    Vector result = r.multiply_left(v);
    
    ASSERT(result.equals({1,4,9}));
}

void MatrixTests::testMatrixVectorTranslate(){
    Vector v = {1,2,3,1};
    TransMatrix r = TransMatrix::translateTransform({-1,-2,-3});
    
    Vector result = r.multiply_left(v);
    
    ASSERT(result.equals({0,0,0}));
}

#pragma mark - Quaternion
void QuaternionTests::testQuaternionMultiplication(){
    Quaternion q1 = {1,2,3,4};
    Quaternion q2 = {4,3,2,1};
    
    Quaternion r = q1.multiply(q2);
    
    ASSERT(r.equals({12,24,6,-12}));
}

void QuaternionTests::testQuaternionInverse(){
    Quaternion q = {1,2,3,4};
    
    Quaternion i = q.inverse();
    
    ASSERT(i.equals({-1/30.0,-1/15.0,-1/10.0,2/15.0}));
}

void QuaternionTests::testQuaternionRotation(){
    
    Quaternion q = Quaternion::quaterion({0,0,1}, M_PI_2);
    Vector i = Vector::i();
    Vector j = Vector::j();
    
    ASSERT(q.rotate(i).equals(j));
}

void QuaternionTests::testQuaternionMatrix(){
    
    Quaternion q = {2,2,2,2};
    
    TransMatrix m = q.matrix();
    
    ASSERT(m.equals({
        0,0,1,0,
        1,0,0,0,
        0,1,0,0,
        0,0,0,1
    }));
}

void QuaternionTests::testQuaternionLERP(){
    
    Quaternion q1 = Quaternion::quaterion({0,0,1}, 0);
    Quaternion q2 = Quaternion::quaterion({0,0,1}, M_PI_2);
    
    Quaternion lerp = q1.LERP(q2, 0.5);
    
    ASSERT(lerp.equals(Quaternion::quaterion({0,0,1}, M_PI_4)));
}

#pragma mark - Plane tests
void PlaneTests::testPlaneContainsPoint(){
    Point p1 = {12,12,3};
    Plane plane = {{0,0,3},{0,0,1}};
    
    ASSERT(plane.containsPoint(p1));
}

#pragma mark - Box tests
void AABBoxTests::testBoxContainsPoint(){
    AABBox b = {{-1,-1,-1},{1,1,1}};
    
    ASSERT(b.containsPoint({0.5, 0.5, 0.5}) == true);
    ASSERT(b.containsPoint({2,2,2}) == false);
}

#pragma mark - Frusta
void FrustaTests::testFrustaContainsPoint(){
    Frusta f = Frusta({{0,0,-1},{0,0,-1}},{{0,0,1},{0,0,1}}, {{0,1,0},{0,1,0}}, {{1,0,0},{0,0,0}}, {{0,-1,0},{0,-1,0}}, {{-1,0,0},{-1,0,0}});
    
    ASSERT(f.containsPoint({0,0.5,0.5}) == true);
    ASSERT(f.containsPoint({0,2,0.5}) == false);
}

#pragma mark - Collection
#pragma mark LinkedList
void LinkedListTests::testLinkedListItemAdded(){
    int i = 2;
    LinkedList<int> l;
    l.add(&i);
    
    int *next = l.root.next->item;
    
    ASSERT(*next == 2);
}

void LinkedListTests::testLinkedListItemFound(){
    int i = 2;
    int j = 3;
    LinkedList<int> l;
    l.add(&i);
    l.add(&j);
    
    Link<int> *found = l.find(&i);
    
    ASSERT(*(found->item) == 2);
}

void LinkedListTests::testLinkedListItemRemoved(){
    int i = 2;
    int j = 3;
    LinkedList<int> l;
    l.add(&i);
    l.add(&j);
    
    Link<int> *found = l.find(&i);
    
    l.remove(found);
    
    found = l.find(&i);
    
    ASSERT(found == NULL);
}

#pragma mark - Allocators
void AlignedAllocatorTests::testAlignedAllocation()
{
    size_t alignment = 16;
    void* p = AlignedAllocator::allocateAligned(30, alignment);
    
    uintptr_t pointer = reinterpret_cast<uintptr_t>(p);
    
    ASSERT((pointer & 0xf) == 0);
}

void AlignedAllocatorTests::testAlignedFree()
{
    void* p = AlignedAllocator::allocateAligned(30, 16);
    
    AlignedAllocator::freeAligned(p);
}

void PoolAllocatorTests::testPoolAllocatorGet()
{
    PoolAllocator<Link<int>, 2> p;
    
    Link<int> *l = p.getItem();
    
    ASSERT((l != NULL) && p.availableAmount() == 1);
}

void PoolAllocatorTests::testPoolAllocatorPut()
{
    PoolAllocator<Link<int>, 2> p;
    
    Link<int> *l = p.getItem();
    
    p.putItem(l);
    
    ASSERT(p.availableAmount() == 2);
}
