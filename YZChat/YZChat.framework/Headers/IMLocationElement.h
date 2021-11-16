//
//  IMLocationElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//


#import <Foundation/Foundation.h>
#import "IMMessageElement.h"

NS_ASSUME_NONNULL_BEGIN


@protocol IMLocationElement <IMMessageElement>

@property (nonatomic, assign, readonly) double latitude;
@property (nonatomic, assign, readonly) double longitude;
@property (nonatomic, strong, nullable, readonly) NSString * desc;

@end

NS_ASSUME_NONNULL_END
