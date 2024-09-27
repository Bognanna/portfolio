package com.mycompany.market_simulator;

import java.util.ArrayList;
import java.util.List;

/**
 * Index class
 * 
 * @author Bogna
 */
public class index {
    private String name;
    private List<Integer> companies_id;
    private float value;
    
    /**
     * Index constructor
     * 
     * @param nam name of the index
     */
    public index(String nam){
        companies_id = new ArrayList<Integer>();
        name = nam;
        value = 0;
    }  
}
