//
//  IMFaceElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//


#import <Foundation/Foundation.h>
#import "IMMessageElement.h"

NS_ASSUME_NONNULL_BEGIN


@protocol IMFaceElement <IMMessageElement>

@property (nonatomic, assign, readonly) NSInteger index;
@property (nonatomic, strong, nullable, readonly) NSData * data;

@end

NS_ASSUME_NONNULL_END
