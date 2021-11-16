//
//  IMTextElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//


#import <Foundation/Foundation.h>
#import "IMMessageElement.h"

NS_ASSUME_NONNULL_BEGIN


@protocol IMTextElement <IMMessageElement>

@property (nonatomic, strong, nullable, readonly) NSString * text;

@end

NS_ASSUME_NONNULL_END
