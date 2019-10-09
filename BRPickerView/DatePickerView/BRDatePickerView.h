//
//  BRDatePickerView.h
//  BRPickerViewDemo
//
//  Created by 任波 on 2017/8/11.
//  Copyright © 2017年 91renb. All rights reserved.
//
//  最新代码下载地址：https://github.com/91renb/BRPickerView

#import "BRBaseView.h"
#import "NSDate+BRPickerView.h"

/// 弹出日期类型
typedef NS_ENUM(NSInteger, BRDatePickerMode) {
    // --- 以下4种是系统自带的样式 ---
    // UIDatePickerModeTime
    BRDatePickerModeTime,              // HH:mm
    // UIDatePickerModeDate
    BRDatePickerModeDate,              // yyyy-MM-dd
    // UIDatePickerModeDateAndTime
    BRDatePickerModeDateAndTime,       // yyyy-MM-dd HH:mm
    // UIDatePickerModeCountDownTimer
    BRDatePickerModeCountDownTimer,    // HH:mm
    // --- 以下7种是自定义样式 ---
    // 年月日时分
    BRDatePickerModeYMDHM,      // yyyy-MM-dd HH:mm
    // 月日时分
    BRDatePickerModeMDHM,       // MM-dd HH:mm
    // 年月日
    BRDatePickerModeYMD,        // yyyy-MM-dd
    // 年月
    BRDatePickerModeYM,         // yyyy-MM
    // 年
    BRDatePickerModeY,          // yyyy
    // 月日
    BRDatePickerModeMD,         // MM-dd
    // 时分
    BRDatePickerModeHM          // HH:mm
};

typedef void(^BRDateResultBlock)(NSString *selectValue);
typedef void(^BRDateCancelBlock)(void);

@class BRPickerStyle;
@interface BRDatePickerView : BRBaseView

/**
 ////////////////////////////////////////////////////////////////////////
 ///   【使用方式一】：传统的创建对象设置属性方式，好处是避免使用方式二导致参数过多
 ///    1. 初始化选择器（使用 initWithPickerMode: 方法）
 ///    2. 设置相关属性
 ///    3. 显示选择器（使用 showWithAnimation: 方法）
 //////////////////////////////////////////////////////////////////////*/

/** 选择器标题 */
@property (nonatomic, strong) NSString *title;
/** 默认选中的时间（值为空/值格式错误时，默认就选中现在的时间） */
@property (nonatomic, strong) NSString *defaultSelValue;

/** 最小时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 minDate） */
@property (nonatomic, strong) NSDate *minDate;
/** 最大时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 maxDate） */
@property (nonatomic, strong) NSDate *maxDate;

/** 是否自动选择，即选择完(滚动完)执行结果回调 */
@property (nonatomic, assign) BOOL isAutoSelect;

/** 自定义UI样式 */
@property (nonatomic, strong) BRPickerStyle *pickerStyle;

/** 选择结果的回调 */
@property (nonatomic, copy) BRDateResultBlock resultBlock;
/** 取消选择的回调 */
@property (nonatomic, copy) BRDateCancelBlock cancelBlock;

/// 初始化方法
/// @param pickerMode 日期显示类型
- (instancetype)initWithPickerMode:(BRDatePickerMode)pickerMode;


/// 弹出视图方法
/// @param animation 是否开启动画
- (void)showWithAnimation:(BOOL)animation;

/// 关闭视图方法
/// @param animation 是否开启动画
- (void)dismissWithAnimation:(BOOL)animation;


/**
//////////////////////////////////////////////////////////////
///   【使用方式二】：快捷使用，直接选择下面其中的一个方法进行使用
//////////////////////////////////////////////////////////////*/
/**
 *  1.显示时间选择器
 *
 *  @param title            标题
 *  @param dateType         日期显示类型
 *  @param defaultSelValue  默认选中的时间（值为空/值格式错误时，默认就选中现在的时间）
 *  @param resultBlock      选择结果的回调
 *
 */
+ (void)showDatePickerWithTitle:(NSString *)title
                       dateType:(BRDatePickerMode)dateType
                defaultSelValue:(NSString *)defaultSelValue
                    resultBlock:(BRDateResultBlock)resultBlock;

/**
 *  2.显示时间选择器（支持 设置自动选择 和 自定义主题颜色）
 *
 *  @param title            标题
 *  @param dateType         日期显示类型
 *  @param defaultSelValue  默认选中的时间（值为空/值格式错误时，默认就选中现在的时间）
 *  @param minDate          最小时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 minDate）
 *  @param maxDate          最大时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 maxDate）
 *  @param isAutoSelect     是否自动选择，即选择完(滚动完)执行结果回调，传选择的结果值
 *  @param themeColor       自定义主题颜色
 *  @param resultBlock      选择结果的回调
 *
 */
+ (void)showDatePickerWithTitle:(NSString *)title
                       dateType:(BRDatePickerMode)dateType
                defaultSelValue:(NSString *)defaultSelValue
                        minDate:(NSDate *)minDate
                        maxDate:(NSDate *)maxDate
                   isAutoSelect:(BOOL)isAutoSelect
                     themeColor:(UIColor *)themeColor
                    resultBlock:(BRDateResultBlock)resultBlock;

/**
 *  3.显示时间选择器（支持 设置自动选择、自定义主题颜色、取消选择的回调）
 *
 *  @param title            标题
 *  @param dateType         日期显示类型
 *  @param defaultSelValue  默认选中的时间（值为空/值格式错误时，默认就选中现在的时间）
 *  @param minDate          最小时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 minDate）
 *  @param maxDate          最大时间，可为空（请使用 NSDate+BRPickerView 分类中和显示类型格式对应的方法创建 maxDate）
 *  @param isAutoSelect     是否自动选择，即选择完(滚动完)执行结果回调，传选择的结果值
 *  @param themeColor       自定义主题颜色
 *  @param resultBlock      选择结果的回调
 *  @param cancelBlock      取消选择的回调
 *
 */
+ (void)showDatePickerWithTitle:(NSString *)title
                       dateType:(BRDatePickerMode)dateType
                defaultSelValue:(NSString *)defaultSelValue
                        minDate:(NSDate *)minDate
                        maxDate:(NSDate *)maxDate
                   isAutoSelect:(BOOL)isAutoSelect
                     themeColor:(UIColor *)themeColor
                    resultBlock:(BRDateResultBlock)resultBlock
                    cancelBlock:(BRDateCancelBlock)cancelBlock;

@end
