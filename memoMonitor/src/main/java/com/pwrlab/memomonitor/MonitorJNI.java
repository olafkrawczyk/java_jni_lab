/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.pwrlab.memomonitor;

/**
 *
 * @author Olaf
 */
public class MonitorJNI {
    
    public static native int getTotalRamMBNative();
    public static native int getUsedRamMBNative();
    
    static {
        System.loadLibrary("com_pwrlab_memomonitor_MonitorJNI");
    }
    
}
