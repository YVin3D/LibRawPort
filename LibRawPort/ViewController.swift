//
//  ViewController.swift
//  LibRawPort
//
//  Created by Youssef Victor on 11/24/19.
//  Copyright © 2019 Youssef Victor. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let bundleURL = Bundle.main.bundleURL
        let imageFileURL = bundleURL.appendingPathComponent("sample.DNG")
        let strPath = imageFileURL.path
        let charArray = strPath.cString(using: .utf8)

        print(getRAWHeight(charArray));
    }
}
