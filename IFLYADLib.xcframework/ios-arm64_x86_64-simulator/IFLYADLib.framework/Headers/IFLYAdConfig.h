//
//  IFLYAdConfig.h
//  IFLYADLib
//
//  Created by admin on 27.2.25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 讯飞广告 SDK 全局配置
/// @discussion 提供 SDK 级别的全局配置项，如个性化推荐开关等。
///             所有配置方法均为类方法，应在广告请求发起前调用。
@interface IFLYAdConfig : NSObject

/// 设置是否开启个性化推荐
/// @param enabled @c YES 开启个性化推荐（默认），@c NO 关闭。
/// @note 当前版本中此接口已预留，具体个性化逻辑待后续版本实现。
///       关闭个性化推荐后，广告投放将不再基于用户行为特征进行定向。
+ (void)setPersonalizedEnabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
