package soluzione3;

import java.io.Serializable;

public class Resource implements Serializable {
	static int count = 0;
	private static final long serialVersionUID = 1L;
	private ResourceType type;
	private int resourceNum;

	public Resource(ResourceType t) {
		setType(t);
		resourceNum = count++;
	}

	public ResourceType getType() {
		return type;
	}

	private void setType(ResourceType type) {
		this.type = type;
	}

	public int getNum() {
		return resourceNum;
	}

}
