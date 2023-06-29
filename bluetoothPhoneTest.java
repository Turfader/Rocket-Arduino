// Initializing the Adapter for bluetooth
private BluetoothAdapter BluetoothAdap = null;
private Set Devices;
// comes in Oncreate method of the activity
BluetoothAdap = BluetoothAdapter.getDefaultAdapter();

// Method to fill the listwith devices
private void pairedDevices()
{
	Devices = BluetoothAdap.getBondedDevices();
	ArrayList list = new ArrayList();

	if (Devices.size() > 0) {
		for (BluetoothDevice bt : Devices) {
			// Add all the available devices to the list
			list.add(bt.getName() + "\n" + bt.getAddress());
		}
	}
	else {
		// In case no device is found
		Toast.makeText(getApplicationContext(), "No Paired Bluetooth Devices Found.", Toast.LENGTH_LONG).show();
	}

	// Adding the devices to the list with ArrayAdapter class
	final ArrayAdapter adapter = new ArrayAdapter(this, android.R.layout.simple_list_item_1, list);
	devicelist.setAdapter(adapter);

	// Method called when the device from the list is clicked
	devicelist.setOnItemClickListener(myListListener);
}
// On click listener for the Listview
private AdapterView.OnItemClickListener myListListener = new AdapterView.OnItemClickListener() {
	public void onItemClick(AdapterView av, View v, int arg2, long arg3)
	{
		// Get the device MAC address
		String name = ((TextView)v).getText().toString();
		String address = info.substring(info.length() - 17);

		// Make an intent to start next activity.
		Intent i = new Intent(MainActivity.this, Control.class);
		// Put the data got from device to the intent
		i.putExtra("add", address); // this will be received at control Activity
		startActivity(i);
	}
};
BluetoothAdapter myBluetooth = null;
BluetoothSocket btSocket = null;
// This UUID is unique and fix id for this device
static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

// receive the address of the bluetooth device
Intent intent = getIntent();
address = intent.getStringExtra("add");

try {
	if (btSocket == null || !isBtConnected) {
		myBluetooth = BluetoothAdapter.getDefaultAdapter();

		// This will connect the device with address as passed
		BluetoothDevice hc = myBluetooth.getRemoteDevice(address);
		btSocket = hc.createInsecureRfcommSocketToServiceRecord(myUUID);
		BluetoothAdapter.getDefaultAdapter().cancelDiscovery();

		Now you will start the connection
			btSocket.connect();
	}
}
catch (IOException e) {
	e.printStackTrace();
}
// Function for commanding the module
private void turnOffLed()
{
	if (btSocket != null) {
		try { // Converting the string to bytes for transferring
			btSocket.getOutputStream().write("0".toString().getBytes());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}
