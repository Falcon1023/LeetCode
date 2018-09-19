package me.trierbo.Codewars.kyu4.Bagels;

import java.lang.reflect.Field;

public class BagelSolver {

    public static Bagel getBagel() {
        try {
            Field value = Boolean.class.getDeclaredField("value");
            value.setAccessible(true);
            value.set(Boolean.TRUE, Boolean.FALSE);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return new Bagel();
    }
}