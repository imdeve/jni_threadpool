package com.wenwp.taskok;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        Button b = (Button) findViewById(R.id.mybtn);

        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MessageReq req = new MessageReq((short)0,(short)0,new byte[3]);
                req.setRequestCallback(new RequestCallback<String>() {
                    @Override
                    public void success(String o) {
                        System.out.println("call call from jni sdk value:"+o);
                        TextView tv = findViewById(R.id.sample_text);
                        tv.append(o);
                    }
                    @Override
                    public void failed(String errorMsg) {

                    }
                });

                MsgSenderMgr.getInstance().sendMsg(req);
            }
        });

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
