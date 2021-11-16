//
//  IMImageElement.h
//  YZChat
//
//  Created by Jinyu Li on 2021/8/27.
//


#import <Foundation/Foundation.h>
#import "IMMessageElement.h"
#import "IMImage.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IMImageElement <IMMessageElement>

@property (nonatomic, strong, nullable, readonly) NSString * localPath;
@property (nonatomic, strong, nullable, readonly) NSArray<IMImage *> * imageList;
- (nullable IMImage *)getIMImage:(YzIMImageType)type;
@end

NS_ASSUME_NONNULL_END
