//
//  VertexData2.h
//  TrenchBroom
//
//  Created by Kristian Duske on 25.01.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "Math.h"

@class MutableFace;
@class BoundingBox;
@class PickingHitList;
@class PickingHit;
@protocol Face;
@protocol Brush;
@protocol Entity;

@interface VertexData : NSObject {
    @private
    NSMutableArray* vertices;
    NSMutableArray* edges;
    NSMutableArray* sides;
    TBoundingBox bounds;
    TVector3f center;
    BOOL valid;
}

- (id)initWithFaces:(NSArray *)faces droppedFaces:(NSMutableSet **)droppedFaces;

- (BOOL)cutWithFace:(MutableFace *)face droppedFaces:(NSMutableSet **)droppedFaces;
- (NSArray *)vertices;
- (NSArray *)edges;
- (int)edgeCount;
- (TBoundingBox *)bounds;
- (TVector3f *)center;

- (void)pick:(TRay *)theRay hitList:(PickingHitList *)theHitList;
- (void)pickEdgeClosestToRay:(TRay *)theRay maxDistance:(float)theMaxDist hitList:(PickingHitList *)theHitList;

- (BOOL)intersectsBrush:(id <Brush>)theBrush;
- (BOOL)containsBrush:(id <Brush>)theBrush;
- (BOOL)intersectsEntity:(id <Entity>)theEntity;
- (BOOL)containsEntity:(id <Entity>)theEntity;
@end
