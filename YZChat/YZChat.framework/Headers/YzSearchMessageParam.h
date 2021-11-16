//
//  YzSearchMessageParam.h
//  YZChat
//
//  Created by Jinyu Li on 2021/9/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YzSearchMessageParam : NSObject

/// 搜索关键字
@property (nonatomic, copy) NSString *keyword;
/**
 * 会话唯一 ID，如果是 C2C 单聊，组成方式为 c2c_userID，如果是群聊，组成方式为 group_groupID
 *
 * 如果为空，代表搜索全部会话。
 * 如果不为空，代表搜索指定会话。
 */
@property (nullable, nonatomic, copy) NSString *conversationId;
/**
 * 分页的页号：用于分页展示查找结果，从零开始起步。
 * 比如：您希望每页展示 10 条结果，请按照如下规则调用：
 * - 首次调用：通过参数 pageSize = 10, pageIndex = 0 调用 searchMessage，从结果回调中的 totalCount 可以获知总共有多少条结果。
 * - 计算页数：可以获知总页数：totalPage = (totalCount % pageSize == 0) ? (totalCount / pageSize) : (totalCount / pageSize + 1) 。
 * - 再次调用：可以通过指定参数 pageIndex （pageIndex < totalPage）返回后续页号的结果。
*/
@property(nonatomic, assign) NSUInteger pageIndex;
/// 每页结果数量：用于分页展示查找结果，如不希望分页可将其设置成 0，但如果结果太多，可能会带来性能问题，默认20。
@property(nonatomic, assign) NSUInteger pageSize;

@end

NS_ASSUME_NONNULL_END
