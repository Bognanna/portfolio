package com.mycompany.market_simulator;

import java.util.ArrayList;
import java.util.List;

/**
 * Currency market class
 * 
 * @author Bogna
 */
public class currency_market extends market {
    private List<currency> list_of_curr;
  
    /**
     * Currency market constructor
     * 
     * @param nam       name
     * @param co        country
     * @param tr_curr   trading currency
     * @param c         city
     * @param ad        address
     */
    public currency_market(String nam, String co, String tr_curr, String c, String ad){
        super(nam, co, tr_curr, c, ad);
        list_of_curr = new ArrayList<currency>();
    }
    
    /**
     * Add currency to the market
     * 
     * @param c     currency
     */
    public void add_to_the_list(currency c){
        list_of_curr.add(c);
    }
    
    /**
     * List of currencies getter
     * 
     * @return  list of currencies
     */
    public List get_list_of_curr(){
        return list_of_curr;
    }

}
