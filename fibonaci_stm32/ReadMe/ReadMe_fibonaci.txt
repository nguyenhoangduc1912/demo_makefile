
A. NVIC (Nested Vectored Interrupt Controller):

1. Chi tiết
	- Xác định ID ngắt cần sử dụng: EXTI0 -> ID interrupt = 5 -> PA0
	- Cập nhận handler interrupt tương ứng trong bảng software vector
	- Thiết lập cho phép ngắt ở mức ngoại vi
		-> GPIO: Input
		-> EXTI:
			--> EXTI_IMR
			--> thiết lập sường ngắt
		-> SYSCFG : SYSCFG_EXTICR1[EXTI0[3:0]]
		
	- Thiết lập mức priority
		-> NVIC_IPR
	- Enable interrupt từ NVIC
	- Bật ngắt toàn cục (enable global interrupt) bằng việc sử dụng lệnh ASM: cpsie i

	- Khi ra khỏi ngắt cần phải xóa cờ ngắt trong NVIC và trong ngoại vi

	#những điều cần lưu ý vs interrupt trên MCU
	bắt buộc hiểu quá tình enable ngắt trên core nivc peripheral
	Một số điều có thể sảy ra với interrupt:
	- thiết lập ngoại vi sai:
		stop ( phụ )
		set cờ pending tương ứng với ngắt trong nivc
		đặt breakpoint trong interrupt handler
		Go debugger
		-> nếu pc dừng lại ở breakpoint cửa interrupt handler => kết luận NVIC + CORE đã thiết lập đúng
	=> Đọc và tìm hiểu ngoại vi xem đang sai ở đâu
	
	- Thiết lập NVIC sai:
		kiểm tra thanh ghi pending để xem cờ ngắt được gửi về thực sự tương tự với ID interrupt nào?
	- Thiết lập core sai:
		liên quan đến thanh ghi  PriMask
		cách thức check
			kiểm tra các cờ pending của ngoại vi + Nvic đã được bật chưa. => Kết luận luôn là có thể core sai
			