//
//  IFLYAdError.h
//  IFLYAdLib
//
//  Created by JzProl.m.Qiezi on 2016/9/26.
//  Copyright © 2016年 iflytek. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 广告错误码枚举
/// @discussion 错误码按范围划分为两类：
///             - **服务端错误 (70xxx)**：由广告服务端返回，表示请求层面的异常。
///             - **客户端错误 (71xxx)**：由 SDK 本地产生，表示参数、网络、环境等问题。
typedef NS_ENUM(NSInteger, IFLYAdErrorCode) {

    // MARK: - 服务端错误码 (70xxx)

    /// 请求成功
    IFLYAdErrorCodeSuccess = 70200,
    /// 请求成功，但没有广告填充
    IFLYAdErrorCodeNotFill         = 70204,
    /// 无效的广告位 ID（服务端校验未通过）
    IFLYAdErrorCodeInvalidAdUnitId = 70400,
    /// 当日广告请求次数已达上限
    IFLYAdErrorCodeOverMaxRequest  = 70403,
    /// 服务端内部错误
    IFLYAdErrorCodeServer          = 70500,

    // MARK: - 客户端错误码 (71xxx)

    /// 未知错误（通常为服务端下发数据解析失败）
    IFLYAdErrorCodeUnknown               = 71001,
    /// 无效的广告请求（请求参数校验未通过）
    IFLYAdErrorCodeInvalidRequest        = 71002,
    /// 网络连接错误
    IFLYAdErrorCodeNetWork               = 71003,
    /// 必要权限未授予（如 IDFA 等）
    IFLYAdErrorCodePermission            = 71004,
    /// 广告位 ID 为空
    IFLYAdErrorCodeEmptyAdUnitId         = 71005,
    /// 广告请求超时
    IFLYAdErrorCodeTimeout               = 71006,
    /// 当前视图控制器为 nil（无法展示广告）
    IFLYAdErrorCodeCurrentViewController = 71007,
    /// 父视图为 nil（无法挂载广告视图）
    IFLYAdErrorCodeFatherView            = 71008,
};

/// 广告错误信息
/// @discussion 封装广告请求或展示过程中的错误信息，包含错误码和错误描述。
///             通过类方法 @c generateByCode: 快捷创建。
@interface IFLYAdError : NSObject

/// 错误描述文本
@property (strong, nonatomic) NSString *errorDescription;

/// 错误码，对应 @c IFLYAdErrorCode 枚举值
@property (assign, nonatomic) int errorCode;

/// 根据错误码生成错误对象
/// @param code 错误码。可传入完整的 5 位错误码（如 @c 71001），
///             也可传入缩写码（如 @c 1001），SDK 会自动补全为 @c 71001。
///             错误描述将根据错误码自动填充。
/// @return 对应的 @c IFLYAdError 实例
+ (IFLYAdError *)generateByCode:(int)code;

/// 根据错误码和自定义描述生成错误对象
/// @param code 错误码，规则同 @c generateByCode:。
/// @param desc 自定义错误描述文本，会覆盖默认的错误描述。
/// @return 对应的 @c IFLYAdError 实例
+ (IFLYAdError *)generateByCode:(int)code description:(NSString *)desc;

@end
