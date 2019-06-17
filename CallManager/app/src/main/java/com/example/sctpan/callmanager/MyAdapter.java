package com.example.sctpan.callmanager;


import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.example.sctpan.callmanager.Entity.PhoneCall;

public class MyAdapter extends ArrayAdapter<PhoneCall> {

    private final Context context;
    private final ArrayList<PhoneCall> itemsArrayList;

    public MyAdapter(Context context, ArrayList<PhoneCall> itemsArrayList) {
        super(context, R.layout.row, itemsArrayList);
        this.context = context;
        this.itemsArrayList = itemsArrayList;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        LayoutInflater inflater = (LayoutInflater) context
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View rowView = inflater.inflate(R.layout.row, parent, false);
        TextView numberText = (TextView) rowView.findViewById(R.id.numberText);
        TextView dateText = (TextView) rowView.findViewById(R.id.dateText);
        numberText.setText(itemsArrayList.get(position).getNumber());
        Date date = new Date(itemsArrayList.get(position).getDate());
        DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
        dateText.setText(dateFormat.format(date));
        return rowView;
    }
}
