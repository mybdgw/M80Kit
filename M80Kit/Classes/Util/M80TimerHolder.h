//
//  M80TimerHolder.h
//  M80Kit
//
//  Created by amao on 5/16/14.
//  Copyright (c) 2014 amao. All rights reserved.
//

//M80TimerHolder，管理某个Timer，功能为
//1.隐藏NSTimer,使得NSTimer只能retain M80TimerHolder
//2.对于非repeats的Timer,执行一次后自动释放Timer
//3.对于repeats的Timer,需要持有M80TimerHolder的对象在析构时调用[M80TimerHolder stopTimer]

#import <Foundation/Foundation.h>

@class M80TimerHolder;

@protocol M80TimerHolderDelegate <NSObject>
- (void)onM80TimerFired:(M80TimerHolder *)holder;
@end

@interface M80TimerHolder : NSObject
@property (nonatomic,weak)  id<M80TimerHolderDelegate>  timerDelegate;

- (void)startTimer:(NSTimeInterval)seconds
          delegate:(id<M80TimerHolderDelegate>)delegate
           repeats:(BOOL)repeats;

- (void)stopTimer;
@end
