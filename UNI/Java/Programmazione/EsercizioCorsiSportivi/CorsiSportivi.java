public enum CorsiSportivi {
	TENNIS {
		public String getOrario() {
			return "lun-ven 9:00-11:00";
		}
	},
	BASKET {
		public String getOrario() {
			return "lun-gio 14:00-17:00";
		}
	},
	PALLAVOLO {
		public String getOrario() {
			return "mar-ven 11:00-13:00";
		}
	},
	CALCIO {
		public String getOrario() {
			return "lun-sab 13:00-17:00";
		}
	},
	BASEBALL {
		public String getOrario() {
			return "mer-dom 16:00-18:00";
		}
	},
	NUOTO {
		public String getOrario() {
			return "mar-sab 14:00-16:00";
		}
	},
	RUGBY {
		public String getOrario() {
			return "mer-ven 9:00-12:00";
		}
	},
	HOCKEY {
		public String getOrario() {
			return "gio-sab 9:00-11:00";
		}
	};
	public abstract String getOrario();
}