//
//  ViewController.h
//  webApp
//
//  Created by Tomer on 24/1/15.
//  Copyright (c) 2015 elasticode. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UIWebViewDelegate>
@property (weak, nonatomic) IBOutlet UIView *splashView;
@property (weak, nonatomic) IBOutlet UIWebView *viewWeb;


@end

