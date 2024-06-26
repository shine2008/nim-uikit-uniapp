//
//  NIMSession.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  会话类型
 */
typedef NS_ENUM(NSInteger, NIMSessionType){
    /**
     *  点对点
     */
    NIMSessionTypeP2P  = 0,
    /**
     *  群组
     */
    NIMSessionTypeTeam = 1,
    /**
     *  聊天室
     */
    NIMSessionTypeChatroom = 2,
    /**
     *  云商服
     */
    NIMSessionTypeYSF  = 3,
    /**
     *  超大群
     */
    NIMSessionTypeSuperTeam = 5,

    /**
     *  圈组
     */
    NIMSessionTypeQChat = 6,
};


/**
 *  会话对象
 */
@interface NIMSession : NSObject<NSCopying>

/**
 *  会话ID,如果当前session为team,则sessionId为teamId,如果是P2P则为对方帐号
 */
@property (nonatomic,copy,readonly)         NSString *sessionId;

/**
 *  会话类型,当前仅支持P2P,Team和Chatroom
 */
@property (nonatomic,assign,readonly)       NIMSessionType sessionType;

/**
 * 圈组频道ID
 */
@property (nonatomic,readonly)              unsigned long long qchatChannelId;

/**
 * 圈组服务器ID
 */
@property (nonatomic,readonly)              unsigned long long qchatServerId;

/**
 *  通过id和type构造会话对象
 *
 *  @param sessionId   会话ID
 *  @param sessionType 会话类型
 *
 *  @return 会话对象实例
 */
+ (instancetype)session:(NSString *)sessionId
                   type:(NIMSessionType)sessionType;

/**
 *  通过圈组频道ID和圈组服务器ID构造会话对象
 *
 *  @param qchatChannelId   圈组频道ID
 *  @param qchatServerId 圈组服务器ID
 *
 *  @return 会话对象实例
 */
+ (instancetype)sessionForQChat:(long long)qchatChannelId
                  qchatServerId:(long long)qchatServerId;

+ (nullable instancetype)sessionFromString:(NSString *)sessionString;
@end

NS_ASSUME_NONNULL_END

