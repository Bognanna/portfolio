package com.mycompany.market_simulator;

/**
 * Company class
 * 
 * @author Bogna
 */
public class company extends kapital{
    
    private String IPO_date;
    private String IPO_share_value;
    private float opening_price;
    private float profit;
    private float revenue;
    private float capital;
    private float trading_volume;
    private float total_sales;
    
    /**
     * Company constructor
     * 
     * @param nam       name
     * @param min_p     minimum price of the asset
     * @param max_p     maximal price of the asset
     * @param curr_p    current price of the asset
     * @param id        identifier of the asset
     * @param IPO_d     IPO date
     * @param IPO_sv    IPO share value
     * @param open_p    opening price
     * @param prof      profit
     * @param rev       revenue
     * @param cap       capital
     * @param trad_v    trading volume
     * @param total_s   total sales
     */
    public company(String name, float p_min, float p_max, float p_current, int id, String IPO_d, String IPO_sv, float open_p, float prof, float rev, float cap, float trad_v, float total_s){
        super(name, p_min, p_max, p_current, id);
        IPO_date = IPO_d;
        IPO_share_value = IPO_sv;
        opening_price = open_p;
        profit = prof;
        revenue = rev;
        capital = cap;
        trading_volume = trad_v;
        total_sales = total_s;
    }
}
