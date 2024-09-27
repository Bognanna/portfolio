package com.mycompany.market_simulator;

import java.util.ArrayList;
import java.util.List;

/**
 * Currency class
 * 
 * @author Bogna
 */
public class currency extends kapital{
    
    private float exchange_rate;
    private List<String> list_of_countries;
    
    /**
     * Currency constructor
     * 
     * @param nam       name
     * @param min_p     minimum price of the asset
     * @param max_p     maximal price of the asset
     * @param curr_p    current price of the asset
     * @param id        identifier of the asset
     * @param ex_r      exchange rate
     */
    public currency(String name, float p_min, float p_max, float p_current, int id, float ex_r){
        super(name, p_min, p_max, p_current, id);
        list_of_countries = new ArrayList<String>();
        exchange_rate = ex_r;
    }
}
