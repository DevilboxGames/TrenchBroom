//
//  Polygon2DIntersection.h
//  TrenchBroom
//
//  Created by Kristian Duske on 28.08.10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "Polygon2D.h"
#import "Edge2D.h"
#import "Vector2f.h"

typedef enum {
    P1U, P1L, P2U, P2L
} CEdge;

@interface Polygon2DIS : NSObject {
    Edge2D* polygon1UpperEdge;
    Edge2D* polygon1LowerEdge;
    Edge2D* polygon2UpperEdge;
    Edge2D* polygon2LowerEdge;
    
    Edge2D* firstUpperEdge;
    Edge2D* lastUpperEdge;
    Edge2D* firstLowerEdge;
    Edge2D* lastLowerEdge;
}

- (id)initWithPolygon1:(Polygon2D *)polygon1 polygon2:(Polygon2D *)polygon2;
- (Polygon2D *)intersection;

- (Edge2D *)forward:(Edge2D *)edge to:(float)x;
- (int)nextEvent;
- (void)addUpper:(Edge2D *)edge;
- (void)addLower:(Edge2D *)edge;
- (void)handlePolygon1UpperEdge;
- (void)handlePolygon1LowerEdge;
- (void)handlePolygon2UpperEdge;
- (void)handlePolygon2LowerEdge;
@end
