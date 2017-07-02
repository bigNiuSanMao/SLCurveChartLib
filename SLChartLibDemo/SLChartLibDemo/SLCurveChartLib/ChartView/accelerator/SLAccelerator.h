//
//  Accelerator.h
//  SLChartLibDemo
//
//  Created by smart on 2017/7/2.
//  Copyright © 2017年 Hadlinks. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VelocityPoint;

typedef void(^DecelerationBlock)(double moveDistance);

@interface SLAccelerator : NSObject
{
    double _decelerationRate;
}
@property (nonatomic,  strong) VelocityPoint* lastVelocity;
@property (nonatomic,  strong) VelocityPoint* currentVelocity;
@property (nonatomic, assign, getter=isEnabled) BOOL    enabled;
//是否运行减速，以及加速的大小
@property (nonatomic,  assign) BOOL   decelerationEnable;
@property (nonatomic,  assign) double decelerationRate;


-(void) panGesStarWith:(double) velocity;
-(double) panGesStateChangeWith:(double) velocity;
-(double) panGesStateEndWith:(double) velocity  decelerationBlock:(DecelerationBlock) deceBlock;
-(void) stopTracking;
@end

@interface VelocityPoint : NSObject
@property (nonatomic, assign) double velocity;   //当前的速度
@property (nonatomic, assign) double time;       //当前的时间，相对于1970的时间

@end
