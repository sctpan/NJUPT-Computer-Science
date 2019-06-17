package com.example.sctpan.callmanager.Entity;

public class PhoneCall {
    private String number;
    private Long date;
    private int uid;
    public PhoneCall(String number, Long date, int uid) {
        this.number = number;
        this.date = date;
        this.uid = uid;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public Long getDate() {
        return date;
    }

    public void setDate(Long date) {
        this.date = date;
    }

    public int getUid() {
        return uid;
    }

    public void setUid(int uid) {
        this.uid = uid;
    }
}
