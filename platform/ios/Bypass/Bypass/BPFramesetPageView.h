//
// Created by Audun Holm Ellertsen on 6/4/13.
// Copyright (c) 2013 Uncodin. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>

#import <CoreText/CoreText.h>
#import <UIKit/UIKit.h>

@class BPDocument;

@protocol BPMarkdownPageViewLinkDelegate;

@interface BPFramesetPageView : UIView
@property (weak, nonatomic) id<BPMarkdownPageViewLinkDelegate> linkDelegate;

- (id)initWithFrame:(CGRect)frame framesetter:(CTFramesetterRef)framesetter;

@end

@protocol BPMarkdownPageViewLinkDelegate <NSObject>
@required

- (void)markdownPageView:(BPFramesetPageView *)markdownPageView
       didHaveLinkTapped:(NSString *)link;

@end
