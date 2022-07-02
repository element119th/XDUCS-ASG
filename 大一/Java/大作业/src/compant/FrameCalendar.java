package compant;

import bean.JiZhang;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;

import javax.swing.*;
import javax.swing.border.TitledBorder;


import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.List;


public class FrameCalendar extends JFrame {

    private Calendar now = Calendar.getInstance();
    private JTextField year = new JTextField(String.valueOf(now.get(java.util.Calendar.YEAR)), 4);
    private JTextField month = new JTextField(String.valueOf(now.get(java.util.Calendar.MONTH) + 1), 2);

    private JButton addyear = new JButton(" >>");
    private JButton subyear = new JButton("<< ");
    private JButton addmonth = new JButton(" > ");
    private JButton submonth = new JButton(" < ");
    private JButton weekday[] = new JButton[7];

    private JLabel day[] = new JLabel[42];
    private JLabel today = new JLabel();
    private static final long serialVersionUID = 1L;

    public FrameCalendar() {

        super("日历");
        File file = new File("./jizhang.data");
        if (file.exists()) {
            try {
                ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(file));
                jiZhangs = (List<JiZhang>) inputStream.readObject();
                inputStream.close();
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
        ImageIcon imageIcon=new ImageIcon("./logo.png");
            setIconImage(imageIcon.getImage());

        Container pane = getContentPane();
        pane.setLayout(new BorderLayout());
        JPanel top = new JPanel();
        JPanel center = new JPanel();
        JPanel foot = new JPanel();
        //透明
        top.setOpaque(false);
        center.setOpaque(false);
        foot.setOpaque(false);
        pane.add(top, BorderLayout.NORTH);
        //button凸起来的效果
        subyear.setBorder(BorderFactory.createRaisedBevelBorder());
        addyear.setBorder(BorderFactory.createRaisedBevelBorder());
        submonth.setBorder(BorderFactory.createRaisedBevelBorder());
        addmonth.setBorder(BorderFactory.createRaisedBevelBorder());
        top.add(subyear);
        top.add(year);
        top.add(addyear);
        top.add(new JLabel("年"));
        top.add(submonth);
        top.add(month);
        top.add(addmonth);
        top.add(new JLabel("月"));
        pane.add(center, BorderLayout.CENTER);
        center.setLayout(new GridLayout(7, 7));
        String[] wd = {"日", "一", "二", "三", "四", "五", "六"};
        for (int i = 0; i < 7; i++) {
            weekday[i] = new JButton(wd[i]);
            weekday[i].setContentAreaFilled(false);
            weekday[i].setFont(new Font("宋体", 1, 16));
            weekday[i].setForeground(Color.BLACK);
            center.add(weekday[i]);
        }
        for (int i = 0; i < 42; i++) {
            day[i] = new JLabel("", JLabel.CENTER);
            center.add(day[i]);
        }
        Create(now.get(java.util.Calendar.YEAR), now.get(java.util.Calendar.MONTH) + 1);
        addyear.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent arg0) {
                year.setText(String.valueOf(Integer.parseInt(year.getText()) + 1));
                Create(Integer.parseInt(year.getText()), Integer.parseInt(month.getText()));

            }
        });
        subyear.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent arg0) {
                year.setText(String.valueOf(Integer.parseInt(year.getText()) - 1));
                Create(Integer.parseInt(year.getText()), Integer.parseInt(month.getText()));

            }
        });
        addmonth.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent arg0) {
                if (Integer.parseInt(month.getText()) == 12)
                    month.setText("1");
                else
                    month.setText(String.valueOf(Integer.parseInt(month.getText()) + 1));
                Create(Integer.parseInt(year.getText()), Integer.parseInt(month.getText()));

            }
        });
        submonth.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent arg0) {
                if (Integer.parseInt(month.getText()) == 1)
                    month.setText("12");
                else
                    month.setText(String.valueOf(Integer.parseInt(month.getText()) - 1));
                Create(Integer.parseInt(year.getText()), Integer.parseInt(month.getText()));

            }

        });
        pane.add(foot, BorderLayout.SOUTH);
        foot.add(today);
        today.setFont(new Font("隶书", Font.PLAIN, 16));
        today.setText(getNowDate());


        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(400, 100, 500, 400);
        ImageIcon bg = new ImageIcon("bg.jpg");

        JLabel label = new JLabel(bg);
        label.setBounds(0, 0, bg.getIconWidth(), bg.getIconHeight());
        getLayeredPane().add(label, new Integer(Integer.MIN_VALUE));
        JPanel jp = (JPanel) getContentPane();
        jp.setOpaque(false);

        setVisible(true);
        setLayout(null);

        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    try {
                        Thread.sleep(1000);
                        today.setText(getNowDate());
                    } catch (InterruptedException e) {

                    }
                }
            }
        });
        thread.start();

        addWindowStateListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                thread.interrupt();
            }
        });
        addData();

    }

    private String getNowDate() {
        now.setTime(new Date());
        return "今天是 公历" + String.valueOf(now.get(java.util.Calendar.YEAR)) + "年"
                + String.valueOf(now.get(java.util.Calendar.MONTH) + 1) + "月"
                + String.valueOf(now.get(java.util.Calendar.DATE)) + "日"
                + "  星期" + String.valueOf(now.get(java.util.Calendar.DAY_OF_WEEK) - 1) +
                " " + now.get(Calendar.HOUR_OF_DAY) + ":" + now.get(Calendar.MINUTE) + ":" + now.get(Calendar.SECOND);

    }

    private JButton jButton = new JButton();
    private JComboBox<String> area = new JComboBox<String>();
    private JLabel jLabel = new JLabel("请选择日期记账：");

    private JComboBox<String> datas = new JComboBox<>();
    private JLabel typeLable = new JLabel("请选择记账类型：");
    private JOptionPane jOptionPane = new JOptionPane();
    private JTextArea priceArea = new JTextArea();
    private JTextArea idArea = new JTextArea();

    private List<JiZhang> jiZhangs = new ArrayList<>();


    private void addData() {
        jButton.setText("记账");
        jButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                jOptionPane.setVisible(!jOptionPane.isVisible());
            }
        });
        jButton.setBounds(500, 30, 60, 30);
        add(jButton);

        area.setBounds(570, 30, 100, 30);

        setSize(1200, getHeight());
        setResizable(false);
        add(area);

        jLabel.setBounds(500, 10, 120, 20);
        add(jLabel);

        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream("./keyword.data")));
            String s = bufferedReader.readLine();

            for (String s1 : s.split(",")) {
                datas.addItem(s1);
            }

            bufferedReader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }


        jOptionPane.setLayout(null);
        jOptionPane.setBounds(500, 60, 200, 500);
        add(jOptionPane);

        datas.setBounds(10, 20, 100, 25);
        jOptionPane.add(datas);

        typeLable.setBounds(10, 0, 110, 25);
        jOptionPane.add(typeLable);

        jOptionPane.setBackground(null);

        JLabel label = new JLabel("请输入费用（元）:");
        label.setBounds(10, 50, 150, 25);
        jOptionPane.add(label);


        priceArea.setBounds(10, 70, 150, 20);
        jOptionPane.add(priceArea);

        label = new JLabel();
        label.setText("请输入记账id:");
        label.setBounds(10, 100, 150, 25);
        jOptionPane.add(label);

        idArea.setBounds(10, 120, 100, 20);
        jOptionPane.add(idArea);

        JButton button = new JButton();
        button.setText("添加记账");
        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                addOneJiZhang();
            }
        });
        button.setBounds(10, 150, 120, 30);

        jOptionPane.add(button);


        addKeyword();
        addOther();
    }

    private JOptionPane jOptionPane2 = new JOptionPane();
    private JLabel label = new JLabel("查询当月的信息：");


    private void addOther() {
        jOptionPane2.setLayout(null);
        jOptionPane2.setBounds(1000, 10, 200, 350);


        label.setBounds(5, 5, 150, 300);
        jOptionPane2.add(label);
        add(jOptionPane2);

        repaint();
        updatedangyue();
        updatejiahanng();

    }

    private JComboBox<String> comboBox = new JComboBox<>();
    private JOptionPane jOptionPanes = new JOptionPane();
    private JList<String> list = new JList<String>();

    private void addKeyword() {
        jOptionPanes.setLayout(null);
        jOptionPanes.setBounds(700, 10, 300, 350);
        add(jOptionPanes);

        comboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                updatejiahanng();
            }
        });
        comboBox.setBounds(5, 20, 100, 20);
        for (int i = 0; i < datas.getItemCount(); i++) {
            String itemAt = datas.getItemAt(i);
            comboBox.addItem(itemAt);
        }
        jOptionPanes.setBorder(new TitledBorder("查询某一类型记账记录"));
        jOptionPanes.add(comboBox);

        list.setBounds(5, 40, 290, 300);
        jOptionPanes.add(list);
    }

    private void updatejiahanng() {
        list.removeAll();
        List<JiZhang> lists = new ArrayList<>();
        String selectedItem = (String) comboBox.getSelectedItem();
        for (JiZhang jiZhang : jiZhangs) {
            if (jiZhang.getType().equals(selectedItem)) {
                lists.add(jiZhang);
            }
        }
        String[] strings = new String[lists.size()];
        for (int i = 0; i < lists.size(); i++) {
            JiZhang jiZhang = lists.get(i);
            strings[i] = jiZhang.toString();
        }
        list.setListData(strings);
    }

    private void addOneJiZhang() {
        String text = idArea.getText();
        if (text.trim().equals("")) {
            JOptionPane.showMessageDialog(null, "请输入记账id！");
            return;
        }
        for (JiZhang jiZhang : jiZhangs) {
            if (jiZhang.getId().equals(text)) {
                JOptionPane.showMessageDialog(null, "记账id已存在，请更换记账id！");
                return;
            }
        }
        JiZhang jiZhang = new JiZhang();
        jiZhang.setId(text);
        jiZhang.setPrice(priceArea.getText());
        jiZhang.setType(datas.getSelectedItem().toString());
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        try {
            jiZhang.setDate(simpleDateFormat.parse(year.getText() + "-" + month.getText() + "-" + area.getSelectedItem().toString()));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        jiZhangs.add(jiZhang);
        JOptionPane.showMessageDialog(null, "添加成功！");
        save();
        updatejiahanng();
        updatedangyue();
    }

    private void updatedangyue() {
        HashMap<String, Integer> a = new LinkedHashMap<>();
        for (int i = 0; i < datas.getItemCount(); i++) {
            String itemAt = (String) datas.getItemAt(i);
            a.put(itemAt, 0);
        }
        List<JiZhang> jiZhang = new ArrayList<>();
        for (JiZhang j : jiZhangs) {

            if (j.getDate().getYear() + 1900 == Integer.valueOf(year.getText())
                    && j.getDate().getMonth() + 1 == Integer.valueOf(month.getText())) {
                jiZhang.add(j);
                if (a.containsKey(j.getType())) {

                    a.put(j.getType(), a.get(j.getType()) + 1);
                }
            }

        }
        String prefix = "<html>当月信息汇总:<br>" + "本月记账总数：" + jiZhang.size() + "<br>";
        int itemCount = datas.getItemCount();
        for (int i = 0; i < itemCount; i++) {
            String itemAt = (String) datas.getItemAt(i);
            Integer integer = a.get(itemAt);
            prefix += itemAt + ":" + integer + "<br>";
        }
        label.setText(prefix + "</html>");

    }

    private void save() {
        try {
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream(new File("./jizhang.data")));

            objectOutputStream.writeObject(jiZhangs);
            objectOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void Create(int y, int m) {
        int j = 0;
        //公历类，一月Calendar.Month=0
        GregorianCalendar date = new GregorianCalendar(y, m - 1, 1);
        date.set(java.util.Calendar.DAY_OF_MONTH, 1);

        List<String> datas = new ArrayList<>();
        //company.FrameCalendar.SUNDAY=1
        for (int i = java.util.Calendar.SUNDAY; i < date.get(java.util.Calendar.DAY_OF_WEEK); i++) {
            day[j++].setText("");
        }
        while (date.get(java.util.Calendar.MONTH) == m - 1) {
            if (date.get(java.util.Calendar.YEAR) == now.get(java.util.Calendar.YEAR) && date.get(java.util.Calendar.MONTH) == now.get(java.util.Calendar.MONTH) && date.get(java.util.Calendar.DAY_OF_MONTH) == now.get(java.util.Calendar.DATE)) {
                day[j].setForeground(Color.MAGENTA);
            } else if (date.get(java.util.Calendar.DAY_OF_WEEK) == java.util.Calendar.SUNDAY) {
                day[j].setForeground(Color.RED);
            } else {
                day[j].setForeground(Color.BLACK);
            }
            day[j].setFont(new Font("宋体", Font.BOLD, 16));
            day[j++].setText(String.valueOf(date.get(java.util.Calendar.DAY_OF_MONTH)));
            datas.add(String.valueOf(date.get(java.util.Calendar.DAY_OF_MONTH)));


            date.add(java.util.Calendar.DAY_OF_MONTH, 1);
        }
        area.removeAllItems();
        for (String data : datas) {

            area.addItem(data);
        }
        updatedangyue();
        while (j < 42) {
            day[j++].setText("");
        }


    }


}
