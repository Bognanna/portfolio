package com.mycompany.market_simulator;

import java.util.ArrayList;
import java.util.List;

/**
 * Stock market class
 * 
 * @author Bogna
 */
public class stock_market extends market {
    private List<index> list_of_idx;
    private List<company> list_of_comp;
  
    /**
     * Stock market constructor
     * 
     * @param nam       name
     * @param co        country
     * @param tr_curr   trading currency
     * @param c         city
     * @param ad        address
     */
    public stock_market(String nam, String co, String tr_curr, String c, String ad){
        super(nam, co, tr_curr, c, ad);
        list_of_idx = new ArrayList<index>();
        list_of_comp = new ArrayList<company>();
    }
    
    /**
     * Add company to the market
     * 
     * @param c company
     */
    public void add_to_the_list(company c){
        list_of_comp.add(c);
    }
    
}
