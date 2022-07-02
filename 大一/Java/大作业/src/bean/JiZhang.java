package bean;

import java.io.Serializable;
import java.util.Date;

/**
 * Author:ryzhao
 * 2022/6/12 18:54
 */
public class JiZhang implements Serializable {
    private String id;
    private Date date;
    private String type;
    private String price;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getPrice() {
        return price;
    }

    public void setPrice(String price) {
        this.price = price;
    }

    @Override
    public String toString() {

        return "ID=" + id + "," + date.toString().split(" ")[0] +
                ", " + type +
                ", " + price;
    }
}
