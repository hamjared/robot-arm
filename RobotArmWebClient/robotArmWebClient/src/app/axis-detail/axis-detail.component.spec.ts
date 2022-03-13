import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AxisDetailComponent } from './axis-detail.component';

describe('AxisDetailComponent', () => {
  let component: AxisDetailComponent;
  let fixture: ComponentFixture<AxisDetailComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ AxisDetailComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(AxisDetailComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
